/*
 * linux/drivers/power/s3c6410_battery.h
 *
 * Battery measurement code for S3C6410 platform.
 *
 * Copyright (C) 2009 Samsung Electronics.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#define DRIVER_NAME	"sec-battery"

/*
 * Battery Table
 */
#define BATT_CAL				2447	/* 3.60V */

#define BATT_MAXIMUM			406		/* 4.176V */
#define BATT_FULL				353		/* 4.10V  */
#define BATT_SAFE_RECHARGE	353		/* 4.10V */
#define BATT_ALMOST_FULL		188		/* 3.8641V */		//322	/* 4.066V */
#define BATT_HIGH				112		/* 3.7554V */		//221	/* 3.919V */
#define BATT_MED				66		/* 3.6907V */		//146	/* 3.811V */
#define BATT_LOW				43		/* 3.6566V */		//112	/* 3.763V */
#define BATT_CRITICAL			8		/* 3.6037V */ 	//(74)	/* 3.707V */
#define BATT_MINIMUM			(-28)	/* 3.554V */		//(38)	/* 3.655V */
#define BATT_OFF				(-128)	/* 3.4029V */		//(-103)	/* 3.45V  */

const int temper_table[][2] =  {
	/* ADC, Temperature (C) */
	{ 1859,		-200}, 
	{ 1846,		-190}, 
	{ 1832,		-180}, 
	{ 1818,		-170}, 
	{ 1804,		-160}, 
	{ 1790,		-150}, 
	{ 1773,		-140}, 
	{ 1756,		-130}, 
	{ 1739,		-120}, 
	{ 1722,		-110}, 
	{ 1705,		-100}, // 10
	{ 1691,		-90 }, 
	{ 1677,		-80 }, 	
	{ 1663,		-70	},
	{ 1649,		-60	},
	{ 1635,		-50	},
	{ 1610,		-40	},
	{ 1586,		-30	},
	{ 1562,		-20	},
	{ 1530,		-10	}, // [[junghyunseok edit temperature table 20100531
	{ 1514,		0	}, // 20
	{ 1497,		10	},
	{ 1479,		20	},
	{ 1465,		30	}, 
	{ 1450,		40	}, // [[junghyunseok edit temperature table 20100531
	{ 1420,		50	}, 
	{ 1406,		60	},
	{ 1386,		70	},
	{ 1366,		80	},
	{ 1346,		90	},
	{ 1326,		100	},
	{ 1302,		110	},
	{ 1278,		120	},
	{ 1254,		130	},
	{ 1230,		140	},
	{ 1206,		150	},
	{ 1182,		160	},
	{ 1158,		170	},
	{ 1134,		180	},
	{ 1110,		190	},
	{ 1086,		200	},
	{ 1059,		210	},
	{ 1035,		220	},
	{ 1011,		230	},
	{ 987,		240	},
	{ 963,		250	},
	{ 937,		260	},
	{ 913,		270	},
	{ 889,		280	},
	{ 865,		290	},
	{ 841,		300	},
	{ 816,		310	},
	{ 794,		320	},
	{ 772,		330	},
	{ 750,		340	},
	{ 728,		350	},
	{ 708,		360	},
	{ 690,		370	},
	{ 672,		380	},
	{ 654,		390	},
	{ 636,		400	},
	{ 616,		410	},
	{ 599,		420	},
	{ 580,		430	}, // [[junghyunseok edit temperature table 20100531
	{ 565,		440	},
	{ 548,		450	},
	{ 529,		460	},
	{ 512,		470	},
	{ 495,		480	},
	{ 478,		490	},
	{ 461,		500	},
	{ 440,		510	}, // [[junghyunseok edit temperature table 20100531
	{ 431,		520	},
	{ 416,		530	},
	{ 401,		540	},
	{ 386,		550	},
	{ 373,		560	},
	{ 360,		570	},
	{ 347,		580	},
	{ 334,		590	},
	{ 321,		600	},
	{ 311,		610	},
	{ 303,		620	},
	{ 296,		630	},
	{ 290 ,		640	}, // [[junghyunseok edit temperature table 20100531
	{ 279,		650	},
	{ 262,		660	},
	{ 248,		670	},
	{ 230,		680	}, // [[junghyunseok edit temperature table 20100531
	{ 220,		690	},
	{ 206,		700	},		
};

#define EVENT_TEMP_HIGH_BLOCK	temper_table[88][0]		// 68 ¡Ë¢çE
#define EVENT_TEMP_HIGH_RECOVER	temper_table[84][0]		// 64 ¡Ë¢çE
#define TEMP_HIGH_BLOCK	temper_table[71][0]		// 51 ¡Ë¢çE
#define TEMP_HIGH_RECOVER	temper_table[63][0]		// 43 ¡Ë¢çE
#define TEMP_LOW_BLOCK		temper_table[19][0]		// -1 temp
#define TEMP_LOW_RECOVER	temper_table[24][0]

/*
 * ADC channel
 */
enum adc_channel_type{
	S3C_ADC_VOLTAGE = 0,
	S3C_ADC_CHG_CURRENT = 2,
	S3C_ADC_EAR = 3,
	S3C_ADC_TEMPERATURE = 6,
	S3C_ADC_V_F,
	ENDOFADC
};
enum {
	BATT_VOL = 0,
	BATT_VOL_ADC,
	BATT_VOL_ADC_CAL,
	BATT_TEMP,
	BATT_TEMP_ADC,
	BATT_TEMP_ADC_CAL,
	BATT_VOL_ADC_AVER,
	BATT_CHARGING_SOURCE,
	BATT_VIBRATOR,
	BATT_CAMERA,
	BATT_MP3,
	BATT_VIDEO,
	BATT_VOICE_CALL_2G,
	BATT_VOICE_CALL_3G,
	BATT_DATA_CALL,
	BATT_WIFI,
	BATT_GPS,
	BATT_DEV_STATE,
	BATT_COMPENSATION,
	BATT_BOOTING,
	BATT_FG_SOC,
	BATT_RESET_SOC,
};

enum {
    CHARGING_MODE_BOOTING,
    BATT_TEMP_CHECK,
    BATT_FULL_CHECK,
};


#define IRQ_TA_CONNECTED_N	IRQ_EINT(19)
#define IRQ_TA_CHG_N			IRQ_EINT(25)
// [[junghyunseok edit for fuel_int interrupt control of fuel_gauge 20100504
#define LOW_BATTERY_IRQ		IRQ_EINT(27)

#define __CHECK_BATTERY_V_F__
#define __CHECK_CHG_CURRENT__
#define __ADJUST_RECHARGE_ADC__
#define __BATTERY_V_F__
#define __BATTERY_COMPENSATION__
#define __TEST_DEVICE_DRIVER__
#define __TEST_MODE_INTERFACE__
#define __FUEL_GAUGES_IC__ 
#define BATT_VF_MAX	750 // 0.55
#define BATT_VF_MIN	450 // 0.45
#define MIN_SOC		0
#define FULL_SOC	92
#define FUEL_INT_1ST	0
#define FUEL_INT_2ND	1
#define FUEL_INT_3RD	2


#define TOTAL_CHARGING_TIME	(6*60*60*1000)	/* 6 hours */
#define TOTAL_RECHARGING_TIME	(1*60*60*1000+30*60*1000)	/* 1.5 hours */

#define COMPENSATE_VIBRATOR		19
#define COMPENSATE_CAMERA		25
#define COMPENSATE_MP3			17
#define COMPENSATE_VIDEO		28
#define COMPENSATE_VOICE_CALL_2G	13
#define COMPENSATE_VOICE_CALL_3G	14
#define COMPENSATE_DATA_CALL		25
#define COMPENSATE_LCD			0
#define COMPENSATE_TA			0
#define COMPENSATE_CAM_FALSH		0
#define COMPENSATE_BOOTING		52
#define COMPENSATE_WIFI			0
#define COMPENSATE_GPS			0	

#define SOC_LB_FOR_POWER_OFF		27

#define RECHARGE_COND_VOLTAGE		4130000
#define RECHARGE_COND_TIME		(30*1000)	/* 30 seconds */

#ifndef __ADJUST_RECHARGE_ADC__	
static int s3c_bat_need_recharging(void);
#endif

static int __init max8998_charger_init(void);
static void __exit max8998_charger_exit(void);
