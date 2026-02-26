/*-----------------------------------*/

#include "_netlink.h"

int sock_fd = 0;
struct sockaddr_nl src_addr;
struct sockaddr_nl dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
struct msghdr msg;


static char argval_s[3][NL_ARG_MAXLEN];

char msg_full[128];
char msg_rx[128];

/*---------------------------------------------------------------------*/
void netlink_close_iface(void)
{
    close(sock_fd);
    free(nlh);
}

/*---------------------------------------------------------------------*/
int netlink_open_iface(void)
{
    memset(&argval_s[0][0],0x00,NL_ARG_MAXLEN);
    memset(&argval_s[1][0],0x00,NL_ARG_MAXLEN);
    memset(&argval_s[2][0],0x00,NL_ARG_MAXLEN);
    sock_fd = socket(AF_NETLINK, SOCK_RAW, NL_REGWRITER); // Create a Netlink socket
    if (sock_fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }
    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); // Own process PID
    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr)); // Bind the socket
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; // Kernel's PID is 0
    dest_addr.nl_groups = 0; // Unicast communication
    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(NL_MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(NL_MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(NL_MAX_PAYLOAD);
    nlh->nlmsg_type = 10; // Custom message type
    nlh->nlmsg_flags = NLM_F_REQUEST; // Request flag
    nlh->nlmsg_seq = 0;
    nlh->nlmsg_pid = getpid();
    return 0;
}

/*---------------------------------------------------------------------*/
int netlink_check_argument(char *strv, int arg_id)
{
    uint32_t rValue = 0;
    int assign_stat = -1;
    assign_stat = sscanf(strv, "%x", &rValue);
    if (assign_stat == 1)
    {
        memcpy(&argval_s[arg_id][0], strv, strlen(strv));
        //printf("NLINK: Number: %08x\n", rValue);
    }
    else
    {
        return NL_APP_INVARG;
    }
    return NL_APP_OK;
}

/*---------------------------------------------------------------------*/
int netlink_check_command(char *strv)
{
    int stat = 0;
    int cmdcode = 0;
    memset(&argval_s[0][0],0x00,NL_ARG_MAXLEN);
	memset(&argval_s[1][0],0x00,NL_ARG_MAXLEN);
	memset(&argval_s[2][0],0x00,NL_ARG_MAXLEN);
    stat = strcmp(strv,"--help");
    if(!stat)
    {
        return NL_APP_OK;
    }
    stat = strcmp(strv,"unmap");
    if(!stat)
    {
        cmdcode = NL_OP_UNMAP;
        sprintf(&argval_s[0][0],"0x%02x", cmdcode);
        return NL_APP_OK;
    }
    stat = strcmp(strv,"remap");
    if(!stat)
    {
        cmdcode = NL_OP_MAP;
        sprintf(&argval_s[0][0],"0x%02x", cmdcode);
        return NL_APP_OK;
    }
    stat = strcmp(strv,"rd");
    if(!stat)
    {
        cmdcode = NL_OP_RD;
        sprintf(&argval_s[0][0],"0x%02x", cmdcode);
        return NL_APP_OK;
    }
    stat = strcmp(strv,"wr");
    if(!stat)
    {
        cmdcode = NL_OP_WR;
        sprintf(&argval_s[0][0],"0x%02x", cmdcode);
        return NL_APP_OK;
    }
    return NL_APP_INVARG;
}

/*---------------------------------------------------------------------*/
int netlink_send_data(void)
{
    memset(&msg_full[0],0x00,128);
    memset(&msg_rx[0],0x00,128);
	strcat(msg_full, argval_s[0]);
    strcat(msg_full, " ");
	strcat(msg_full, argval_s[1]);
    strcat(msg_full, " ");
    strcat(msg_full, argval_s[2]);
    // Add payload
    strcpy(NLMSG_DATA(nlh), msg_full);
    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    sendmsg(sock_fd, &msg, 0); // Send the message
    recvmsg(sock_fd, &msg, 0);
    memcpy(&msg_rx[0],(char *)NLMSG_DATA(nlh),strlen((char *)NLMSG_DATA(nlh)));
    //close(sock_fd);
    //free(nlh);
    return NL_APP_OK;
}
/*---------------------------------------------------------------------*/
