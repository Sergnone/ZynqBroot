#ifndef _DGLNT_DYNCLK_H
#define _DGLNT_DYNCLK_H

#include <linux/platform_device.h>
#include <linux/clk-provider.h>
#include <linux/clk.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/delay.h>

struct dglnt_dynclk_reg{
    uint32_t clk0L;
    uint32_t clkFBL;
    uint32_t clkFBH_clk0H;
    uint32_t divclk;
    uint32_t lockL;
    uint32_t fltr_lockH;
};

struct dglnt_dynclk_mode{
    uint32_t freq;
    uint32_t fbmult;
    uint32_t clkdiv;
    uint32_t maindiv;
};

struct dglnt_dynclk {
    void __iomem *base;
    struct clk_hw clk_hw;
    unsigned long freq;
};


uint32_t dglnt_dynclk_divider(uint32_t divide);
uint32_t dglnt_dynclk_count_calc(uint32_t divide);
void dglnt_dynclk_write_reg (struct dglnt_dynclk_reg *regValues, void __iomem *baseaddr);
uint32_t dglnt_dynclk_find_mode(uint32_t freq, uint32_t parentFreq, struct dglnt_dynclk_mode *bestPick);
int dglnt_dynclk_find_reg (struct dglnt_dynclk_reg *regValues, struct dglnt_dynclk_mode *clkParams);
int dglnt_dynclk_start_work(struct dglnt_dynclk *dglnt_dynclk,
							unsigned long parent_rate);
#endif