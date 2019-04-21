#include <asm/jzsoc.h> 

void cim_power_off(void)
{
	__gpio_as_output(3*32+12);
	__gpio_clear_pin(3*32+12);
	msleep(1);
	cpm_stop_clock(CGM_CIM);
}

void cim_power_on(void)
{
	__gpio_as_output(3*32+12);
	__gpio_set_pin(3*32+12);
	msleep(1);
	cpm_stop_clock(CGM_CIM);
	cpm_set_clock(CGU_CIMCLK,24000000);
	cpm_start_clock(CGM_CIM);
}




