#ifndef _DYNCLK_DRV_H
#define _DYNCLK_DRV_H

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
    u32 clk0L;
    u32 clkFBL;
    u32 clkFBH_clk0H;
    u32 divclk;
    u32 lockL;
    u32 fltr_lockH;
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


uint32_t dglnt_dynclk_divider(u32 divide);
uint32_t dglnt_dynclk_count_calc(u32 divide);
void dglnt_dynclk_write_reg (struct dglnt_dynclk_reg *regValues, void __iomem *baseaddr);
uint32_t dglnt_dynclk_find_mode(u32 freq, u32 parentFreq, struct dglnt_dynclk_mode *bestPick);
int dglnt_dynclk_find_reg (struct dglnt_dynclk_reg *regValues, struct dglnt_dynclk_mode *clkParams);
int dglnt_dynclk_start_work(struct dglnt_dynclk *dglnt_dynclk,
							unsigned long parent_rate);
#endif