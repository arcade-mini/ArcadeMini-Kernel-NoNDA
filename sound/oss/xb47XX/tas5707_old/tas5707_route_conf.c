/*
 * Linux/sound/oss/jz4760_route_conf.h
 *
 * DLV CODEC driver for Ingenic Jz4760 MIPS processor
 *
 * 2010-11-xx   jbbi <jbbi@ingenic.cn>
 *
 * Copyright (c) Ingenic Semiconductor Co., Ltd.
 */

#include "tas5707_route_conf.h"

/***************************************************************************************\
 *                                                                                     *
 *typical config for each route                                                        *
 *                                                                                     *
\***************************************************************************************/
unsigned int DEFAULT_REPLAY_ROUTE = REPLAY_HP_STEREO;
unsigned int DEFAULT_RECORD_ROUTE = RECORD_MIC1_MONO_DIFF_WITH_BIAS;
unsigned int DEFAULT_CALL_RECORD_ROUTE = RECORD_STEREO_MIC_DIFF_WITH_BIAS_BYPASS_MIXER_MIC2_TO_OUT;
/*######################################################################################################*/
route_conf_base const tas5707_record_mic1_mono_diff_with_bias_conf;
route_conf_base const tas5707_record_mic1_mono_diff_without_bias_conf;
route_conf_base const tas5707_record_mic1_mono_sing_with_bias_conf;
route_conf_base const tas5707_record_mic1_mono_sing_without_bias_conf;
route_conf_base const tas5707_record_mic2_mono_diff_with_bias_conf;
route_conf_base const tas5707_record_mic2_mono_diff_without_bias_conf;
route_conf_base const tas5707_record_mic2_mono_sing_with_bias_conf;
route_conf_base const tas5707_record_mic2_mono_sing_without_bias_conf;
route_conf_base const tas5707_record_stereo_mic1_left_diff_with_bias_conf;
route_conf_base const tas5707_record_stereo_mic1_left_diff_without_bias_conf;
route_conf_base const tas5707_record_stereo_mic1_left_sing_with_bias_conf;
route_conf_base const tas5707_record_stereo_mic1_left_sing_without_bias_conf;
route_conf_base const tas5707_record_stereo_mic2_left_diff_with_bias_conf;
route_conf_base const tas5707_record_stereo_mic2_left_diff_without_bias_conf;
route_conf_base const tas5707_record_stereo_mic2_left_sing_with_bias_conf;
route_conf_base const tas5707_record_stereo_mic2_left_sing_without_bias_conf;
route_conf_base const tas5707_record_linein_conf;
/*##########################################################################################################*/
route_conf_base const tas5707_replay_out_conf = {
	.route_ready_mode = ROUTE_READY_FOR_DAC, //fix
	/*--------route-----------*/
	//replay
	.route_replay_mixer_mode = REPLAY_MIXER_PLAYBACK_DAC_ONLY, //fix
	.route_replay_filter_mode = REPLAY_FILTER_STEREO, //fix
	.route_dac_mode = DAC_STEREO, //fix
	.route_replay_mux_mode = REPLAY_MUX_DAC_OUTPUT, //fix
};

route_conf_base const tas5707_replay_hp_stereo_conf = {
	.route_ready_mode = ROUTE_READY_FOR_DAC, //fix
	/*--------route-----------*/
	//replay
	.route_replay_mixer_mode = REPLAY_MIXER_PLAYBACK_DAC_ONLY, //fix
	.route_replay_filter_mode = REPLAY_FILTER_STEREO, //fix
	.route_dac_mode = DAC_STEREO, //fix
	.route_replay_mux_mode = REPLAY_MUX_DAC_OUTPUT, //fix
	.route_hp_mode = HP_ENABLE, //fix
	.route_lineout_mode = LINEOUT_DISABLE, //..
	.route_btl_mode = BTL_DISABLE, //..
};

route_conf_base const tas5707_replay_lineout_mono_conf;
route_conf_base const tas5707_replay_lineout_stereo_conf;
route_conf_base const tas5707_replay_btl_conf;
/*########################################################################################################*/
route_conf_base const tas5707_bypass_mic1_diff_with_bias_to_out_conf;
route_conf_base const tas5707_bypass_mic1_diff_with_bias_to_hp_conf;
route_conf_base const tas5707_bypass_mic1_diff_with_bias_to_lineout_mono_conf;
route_conf_base const tas5707_bypass_mic1_diff_with_bias_to_lineout_stereo_conf;
route_conf_base const tas5707_bypass_mic1_diff_with_bias_to_btl_conf;
route_conf_base const tas5707_bypass_mic2_diff_with_bias_to_out_conf;
route_conf_base const tas5707_bypass_mic2_diff_with_bias_to_hp_conf;
route_conf_base const tas5707_bypass_mic2_diff_with_bias_to_lineout_mono_conf;
route_conf_base const tas5707_bypass_mic2_diff_with_bias_to_lineout_stereo_conf;
route_conf_base const tas5707_bypass_mic2_diff_with_bias_to_btl_conf;
route_conf_base const tas5707_bypass_linein_to_out_conf;
route_conf_base const tas5707_bypass_linein_to_hp_conf;
route_conf_base const tas5707_bypass_linein_to_lineout_mono_conf; 
route_conf_base const tas5707_bypass_linein_to_lineout_stereo_conf;
route_conf_base const tas5707_bypass_linein_to_btl_conf;
/*##############################################################################################################*/

route_conf_base const tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_out_conf;
route_conf_base const tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_hp_conf;
route_conf_base const tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_lineout_mono_conf;
route_conf_base const tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_btl_conf;
/*##############################################################################################################*/

route_conf_base const tas5707_record_mic2_mono_diff_without_bias_replay_lineout_mono_conf;
/*##############################################################################################################*/
/*??????????????????????????????????????????????????????????????????????????????????????????????????????????????*/

route_conf_base const tas5707_route_all_clear_conf = {
	.route_ready_mode = ROUTE_READY_FOR_DAC, //fix
	/*--------route-----------*/
	.route_mic1_mode = MIC1_DISABLE, //..
	.route_mic2_mode = MIC2_DISABLE, //..
	.route_linein_mode = LINEIN_DISABLE, //..
	.route_adc_mode = ADC_DISABLE, //..
	//replay
	.route_dac_mode = DAC_DISABLE, //..
	.route_hp_mode = HP_DISABLE, //..
	.route_lineout_mode = LINEOUT_DISABLE, //..
	.route_btl_mode = BTL_DISABLE, //..
};

route_conf_base const tas5707_route_replay_clear_conf = {
	.route_ready_mode = ROUTE_READY_FOR_DAC, //fix
	/*--------route-----------*/
	.route_dac_mode = DAC_DISABLE, //..
	.route_hp_mode = HP_DISABLE, //..
	.route_lineout_mode = LINEOUT_DISABLE, //..
	.route_btl_mode = BTL_DISABLE, //..
};

route_conf_base const tas5707_route_record_clear_conf = {
	.route_ready_mode = ROUTE_READY_FOR_DAC, //fix
	/*--------route-----------*/
	.route_mic1_mode = MIC1_DISABLE, //..
	.route_mic2_mode = MIC2_DISABLE, //..
	.route_linein_mode = LINEIN_DISABLE, //..
	.route_adc_mode = ADC_DISABLE, //..
};

/*######################################################################################################*/

struct __dlv_route_info tas5707_dlv_route_info[] = {

	/************************ route clear ************************/
	{
		.route_name = ROUTE_ALL_CLEAR,
		.route_conf = &tas5707_route_all_clear_conf,
	},
	{
		.route_name = ROUTE_REPLAY_CLEAR,
		.route_conf = &tas5707_route_replay_clear_conf,
	},
	{
		.route_name = ROUTE_RECORD_CLEAR,
		.route_conf = &tas5707_route_record_clear_conf,
	},

	/*********************** record route *************************/
	{
		.route_name = RECORD_MIC1_MONO_DIFF_WITH_BIAS,
		.route_conf = &tas5707_record_mic1_mono_diff_with_bias_conf,
	},
	{
		.route_name = RECORD_MIC1_MONO_DIFF_WITHOUT_BIAS,
		.route_conf = &tas5707_record_mic1_mono_diff_without_bias_conf,
	},
	{
		.route_name = RECORD_MIC2_MONO_DIFF_WITH_BIAS,
		.route_conf = &tas5707_record_mic2_mono_diff_with_bias_conf,
	},
	{
		.route_name = RECORD_MIC2_MONO_DIFF_WITHOUT_BIAS,
		.route_conf = &tas5707_record_mic2_mono_diff_without_bias_conf,
	},

	/*********************** replay route **************************/
	{
		.route_name = REPLAY_OUT,
		.route_conf = &tas5707_replay_out_conf,
	},
	{
		.route_name = REPLAY_HP_STEREO,
		.route_conf = &tas5707_replay_hp_stereo_conf,
	},
	{
		.route_name = REPLAY_LINEOUT_MONO,
		.route_conf = &tas5707_replay_lineout_mono_conf,
	},
	{
		.route_name = REPLAY_BTL,
		.route_conf = &tas5707_replay_btl_conf,
	},

	/*********************** bypass route *************************/
	{
		.route_name = BYPASS_MIC1_DIFF_WITH_BIAS_TO_OUT,
		.route_conf = &tas5707_bypass_mic1_diff_with_bias_to_out_conf,
	},
	{
		.route_name = BYPASS_MIC1_DIFF_WITH_BIAS_TO_HP,
		.route_conf = &tas5707_bypass_mic1_diff_with_bias_to_hp_conf,
	},
	{
		.route_name = BYPASS_MIC1_DIFF_WITH_BIAS_TO_LINEOUT_MONO,
		.route_conf = &tas5707_bypass_mic1_diff_with_bias_to_lineout_mono_conf,
	},
	{
		.route_name = BYPASS_MIC1_DIFF_WITH_BIAS_TO_BTL,
		.route_conf = &tas5707_bypass_mic1_diff_with_bias_to_btl_conf,
	},
	{
		.route_name = BYPASS_MIC2_DIFF_WITH_BIAS_TO_OUT,
		.route_conf = &tas5707_bypass_mic2_diff_with_bias_to_out_conf,
	},
	{
		.route_name = BYPASS_MIC2_DIFF_WITH_BIAS_TO_HP,
		.route_conf = &tas5707_bypass_mic2_diff_with_bias_to_hp_conf,
	},
	{
		.route_name = BYPASS_MIC2_DIFF_WITH_BIAS_TO_LINEOUT_MONO,
		.route_conf = &tas5707_bypass_mic2_diff_with_bias_to_lineout_mono_conf,
	},
	{
		.route_name = BYPASS_MIC2_DIFF_WITH_BIAS_TO_BTL,
		.route_conf = &tas5707_bypass_mic2_diff_with_bias_to_btl_conf,
	},
	{
		.route_name = BYPASS_LINEIN_TO_OUT,
		.route_conf = &tas5707_bypass_linein_to_out_conf,
	},
	{
		.route_name = BYPASS_LINEIN_TO_HP,
		.route_conf = &tas5707_bypass_linein_to_hp_conf,
	},
	{
		.route_name = BYPASS_LINEIN_TO_LINEOUT_MONO,
		.route_conf = &tas5707_bypass_linein_to_lineout_mono_conf,
	},
	{
		.route_name = BYPASS_LINEIN_TO_BTL,
		.route_conf = &tas5707_bypass_linein_to_btl_conf,
	},

	/********************* bypass mixer route ********************/
	{
		.route_name = RECORD_STEREO_MIC_DIFF_WITH_BIAS_BYPASS_MIXER_MIC2_TO_OUT,
		.route_conf = &tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_out_conf,
	},
	{
		.route_name = RECORD_STEREO_MIC_DIFF_WITH_BIAS_BYPASS_MIXER_MIC2_TO_HP,
		.route_conf = &tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_hp_conf,
	},
	{
		.route_name = RECORD_STEREO_MIC_DIFF_WITH_BIAS_BYPASS_MIXER_MIC2_TO_LINEOUT_MONO,
		.route_conf = &tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_lineout_mono_conf,
	},
	{
		.route_name = RECORD_STEREO_MIC_DIFF_WITH_BIAS_BYPASS_MIXER_MIC2_TO_BTL,
		.route_conf = &tas5707_record_stereo_mic_diff_with_bias_bypass_mixer_mic2_to_btl_conf,
	},
	
	/********************* misc route ****************************/
	{
		.route_name = RECORD_MIC2_MONO_DIFF_WITHOUT_BIAS_REPLAY_LINEOUT_MONO,
		.route_conf = &tas5707_record_mic2_mono_diff_without_bias_replay_lineout_mono_conf,
	},
}; 
