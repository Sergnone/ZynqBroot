#!/bin/bash

DTSDIR=../platform/dts
SDTDIR=../platform/workspace/platform/hw/sdt
HWARTDIR=../platform/workspace/platform/zynq_fsbl/zynq_fsbl_bsp/hw_artifacts

#sudo rm $DTSDIR/sdt.dtb
#sudo rm $DTSDIR/sdt.dts
sudo rm $DTSDIR/devicetree.dtb
#cp $HWARTDIR/sdt.dts $DTSDIR

#RADDR="0x40000000"
#STEP=0
#UPDLINE=0
#TEMP_FILE=$(mktemp)
#INPUT_FILE="$DTSDIR/sdt.dts"
#while IFS= read -r line; do
#    if [ "$STEP" -eq "0" ]; then
#        if [ "$UPDLINE" -eq "0" ]; then
#            PATTERN="&ps7_ram_0_memory 0x0 0x30000>,"
#            OLDLINE=$(grep "$PATTERN" $DTSDIR/sdt.dts)
#            NVALUE=$RADDR
#            NEWLINE=${OLDLINE/0x30000/$NVALUE}
#            UPDLINE=$((UPDLINE + 1))
#        fi
#    else
#        if [ "$STEP" -eq "1" ]; then
#            if [ "$UPDLINE" -eq "0" ]; then
#                PATTERN="<0x0 0x30000 0x0 0x40000>;"
#                OLDLINE=$(grep "$PATTERN" $DTSDIR/sdt.dts)
#                NVALUE=$RADDR
#                NEWLINE=${OLDLINE/0x30000 0x0 0x40000/$NVALUE}
#                UPDLINE=$((UPDLINE + 1))
#            fi
#        else
#            if [ "$STEP" -eq "2" ]; then
#                if [ "$UPDLINE" -eq "0" ]; then
#                    PATTERN="<0x0 0x30000>;"
#                    OLDLINE=$(grep "$PATTERN" $DTSDIR/sdt.dts)
#                    NVALUE=$RADDR
#                    NEWLINE=${OLDLINE/0x30000/$NVALUE}
#                    UPDLINE=$((UPDLINE + 1))
#                fi
#            fi        
#        fi
#    fi 
#    if [[ "$line" == "$OLDLINE" ]]; then
#        echo "$NEWLINE" >> "$TEMP_FILE"
#        STEP=$((STEP + 1))
#        UPDLINE=$((UPDLINE - 1))
#    else
#        echo "$line" >> "$TEMP_FILE"
#    fi
#done < "$INPUT_FILE"
#mv "$TEMP_FILE" "$INPUT_FILE"

#dtc -I dts -O dtb -o $DTSDIR/sdt.dtb $DTSDIR/sdt.dts
dtc -I dts -O dtb -o $DTSDIR/sdt.dtb $DTSDIR/sdt-smp.dts

mv $DTSDIR/sdt.dtb $DTSDIR/devicetree.dtb
cp $DTSDIR/devicetree.dtb  ../images


