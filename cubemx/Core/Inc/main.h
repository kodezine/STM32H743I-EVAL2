/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DB28_Pin GPIO_PIN_6
#define DB28_GPIO_Port GPIOI
#define SDRAM_DQM3_Pin GPIO_PIN_5
#define SDRAM_DQM3_GPIO_Port GPIOI
#define SDRAM_DQM2_Pin GPIO_PIN_4
#define SDRAM_DQM2_GPIO_Port GPIOI
#define RXD_CAN_COL_Pin GPIO_PIN_5
#define RXD_CAN_COL_GPIO_Port GPIOB
#define nIR1_IN_Pin GPIO_PIN_5
#define nIR1_IN_GPIO_Port GPIOK
#define ADIS_nCS_Pin GPIO_PIN_10
#define ADIS_nCS_GPIO_Port GPIOG
#define ADIS_MISO_Pin GPIO_PIN_9
#define ADIS_MISO_GPIO_Port GPIOG
#define TXD_ISM_BackUp_Pin GPIO_PIN_5
#define TXD_ISM_BackUp_GPIO_Port GPIOD
#define TX_ISM_EN_BackUp_Pin GPIO_PIN_4
#define TX_ISM_EN_BackUp_GPIO_Port GPIOD
#define TXD_ISM_Pin GPIO_PIN_10
#define TXD_ISM_GPIO_Port GPIOC
#define DB25_Pin GPIO_PIN_1
#define DB25_GPIO_Port GPIOI
#define DB24_Pin GPIO_PIN_0
#define DB24_GPIO_Port GPIOI
#define DB29_Pin GPIO_PIN_7
#define DB29_GPIO_Port GPIOI
#define SDRAM_DQM1_Pin GPIO_PIN_1
#define SDRAM_DQM1_GPIO_Port GPIOE
#define SCL_Pin GPIO_PIN_6
#define SCL_GPIO_Port GPIOB
#define STAT_3V_CC_Pin GPIO_PIN_4
#define STAT_3V_CC_GPIO_Port GPIOK
#define ADIS_SCK_Pin GPIO_PIN_11
#define ADIS_SCK_GPIO_Port GPIOG
#define STAT_5V_CC_Pin GPIO_PIN_15
#define STAT_5V_CC_GPIO_Port GPIOJ
#define RXD_ISM_BackUp_Pin GPIO_PIN_6
#define RXD_ISM_BackUp_GPIO_Port GPIOD
#define IR1_Enable_Pin GPIO_PIN_3
#define IR1_Enable_GPIO_Port GPIOD
#define RXD_ISM_Pin GPIO_PIN_11
#define RXD_ISM_GPIO_Port GPIOC
#define DB26_Pin GPIO_PIN_2
#define DB26_GPIO_Port GPIOI
#define DB23_Pin GPIO_PIN_15
#define DB23_GPIO_Port GPIOH
#define DB22_Pin GPIO_PIN_14
#define DB22_GPIO_Port GPIOH
#define SDRAM_DQM0_Pin GPIO_PIN_0
#define SDRAM_DQM0_GPIO_Port GPIOE
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOB
#define STAT_3V3_ISM_Pin GPIO_PIN_3
#define STAT_3V3_ISM_GPIO_Port GPIOK
#define ISM_nBOOTLOADER_BackUp_Pin GPIO_PIN_7
#define ISM_nBOOTLOADER_BackUp_GPIO_Port GPIOD
#define TXD_CC_Pin GPIO_PIN_12
#define TXD_CC_GPIO_Port GPIOC
#define DB27_Pin GPIO_PIN_3
#define DB27_GPIO_Port GPIOI
#define nSHDN_CC_Pin GPIO_PIN_9
#define nSHDN_CC_GPIO_Port GPIOB
#define SDRAM_nCAS_Pin GPIO_PIN_15
#define SDRAM_nCAS_GPIO_Port GPIOG
#define nIR2_IN_Pin GPIO_PIN_7
#define nIR2_IN_GPIO_Port GPIOK
#define nRST_IN_Pin GPIO_PIN_14
#define nRST_IN_GPIO_Port GPIOG
#define WDRESET_Pin GPIO_PIN_13
#define WDRESET_GPIO_Port GPIOG
#define _5V_CC_ON_Pin GPIO_PIN_14
#define _5V_CC_ON_GPIO_Port GPIOJ
#define _5V_ON_Pin GPIO_PIN_12
#define _5V_ON_GPIO_Port GPIOJ
#define IR2_Enable_Pin GPIO_PIN_2
#define IR2_Enable_GPIO_Port GPIOD
#define DB2_Pin GPIO_PIN_0
#define DB2_GPIO_Port GPIOD
#define TXLB_CAN_TT_Pin GPIO_PIN_10
#define TXLB_CAN_TT_GPIO_Port GPIOA
#define DIAG_CAN_TT_Pin GPIO_PIN_9
#define DIAG_CAN_TT_GPIO_Port GPIOA
#define DB21_Pin GPIO_PIN_13
#define DB21_GPIO_Port GPIOH
#define DB30_Pin GPIO_PIN_9
#define DB30_GPIO_Port GPIOI
#define TX_ISM_EN_Pin GPIO_PIN_13
#define TX_ISM_EN_GPIO_Port GPIOC
#define ISM_nBOOTLOADER_Pin GPIO_PIN_8
#define ISM_nBOOTLOADER_GPIO_Port GPIOI
#define STAT_5V_Pin GPIO_PIN_13
#define STAT_5V_GPIO_Port GPIOJ
#define DB3_Pin GPIO_PIN_1
#define DB3_GPIO_Port GPIOD
#define RTS_CC_Pin GPIO_PIN_8
#define RTS_CC_GPIO_Port GPIOC
#define CTS_CC_Pin GPIO_PIN_9
#define CTS_CC_GPIO_Port GPIOC
#define nREED_DIR_Pin GPIO_PIN_8
#define nREED_DIR_GPIO_Port GPIOA
#define TXD_CAN_TT_Pin GPIO_PIN_12
#define TXD_CAN_TT_GPIO_Port GPIOA
#define RXD_CAN_TT_Pin GPIO_PIN_11
#define RXD_CAN_TT_GPIO_Port GPIOA
#define DB31_Pin GPIO_PIN_10
#define DB31_GPIO_Port GPIOI
#define RXD_CC_BackUp_Pin GPIO_PIN_7
#define RXD_CC_BackUp_GPIO_Port GPIOC
#define TXD_CC_BackUp_Pin GPIO_PIN_6
#define TXD_CC_BackUp_GPIO_Port GPIOC
#define SDRAM_CLK_Pin GPIO_PIN_8
#define SDRAM_CLK_GPIO_Port GPIOG
#define DIO_WedgeS_Pin GPIO_PIN_7
#define DIO_WedgeS_GPIO_Port GPIOG
#define AB2_Pin GPIO_PIN_2
#define AB2_GPIO_Port GPIOF
#define AB1_Pin GPIO_PIN_1
#define AB1_GPIO_Port GPIOF
#define AB0_Pin GPIO_PIN_0
#define AB0_GPIO_Port GPIOF
#define BA1_Pin GPIO_PIN_5
#define BA1_GPIO_Port GPIOG
#define TE_485_RC_Pin GPIO_PIN_6
#define TE_485_RC_GPIO_Port GPIOG
#define REED_DIR_CC_Pin GPIO_PIN_12
#define REED_DIR_CC_GPIO_Port GPIOI
#define REED_REF_CC_Pin GPIO_PIN_13
#define REED_REF_CC_GPIO_Port GPIOI
#define AB3_Pin GPIO_PIN_3
#define AB3_GPIO_Port GPIOF
#define BA0_Pin GPIO_PIN_4
#define BA0_GPIO_Port GPIOG
#define TXLBEN_CAN_TT_Pin GPIO_PIN_3
#define TXLBEN_CAN_TT_GPIO_Port GPIOG
#define TXLB_CAN_COL_Pin GPIO_PIN_2
#define TXLB_CAN_COL_GPIO_Port GPIOG
#define ISM_3V3_ON_Pin GPIO_PIN_2
#define ISM_3V3_ON_GPIO_Port GPIOK
#define AB5_Pin GPIO_PIN_5
#define AB5_GPIO_Port GPIOF
#define AB4_Pin GPIO_PIN_4
#define AB4_GPIO_Port GPIOF
#define _3V_CC_ON_Pin GPIO_PIN_0
#define _3V_CC_ON_GPIO_Port GPIOK
#define RXD_485_RC_Pin GPIO_PIN_6
#define RXD_485_RC_GPIO_Port GPIOF
#define TXD_485_RC_Pin GPIO_PIN_7
#define TXD_485_RC_GPIO_Port GPIOF
#define DIR_485_RC_Pin GPIO_PIN_8
#define DIR_485_RC_GPIO_Port GPIOF
#define STAT_12V_RC_ERROR_Pin GPIO_PIN_11
#define STAT_12V_RC_ERROR_GPIO_Port GPIOJ
#define ADC_Footswitch2_Pin GPIO_PIN_0
#define ADC_Footswitch2_GPIO_Port GPIOC
#define ADC_Footswitch1_Pin GPIO_PIN_10
#define ADC_Footswitch1_GPIO_Port GPIOF
#define ADC_TT_Current_Pin GPIO_PIN_9
#define ADC_TT_Current_GPIO_Port GPIOF
#define _12V_RC_ON_Pin GPIO_PIN_10
#define _12V_RC_ON_GPIO_Port GPIOJ
#define ADC_Footswitch3_Pin GPIO_PIN_1
#define ADC_Footswitch3_GPIO_Port GPIOC
#define ADC_Footswitch4_Pin GPIO_PIN_2
#define ADC_Footswitch4_GPIO_Port GPIOC
#define STAT_12V_FUSE_Pin GPIO_PIN_9
#define STAT_12V_FUSE_GPIO_Port GPIOJ
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOH
#define STATUS_40V_TT_Pin GPIO_PIN_2
#define STATUS_40V_TT_GPIO_Port GPIOA
#define TT_Detect_Pin GPIO_PIN_1
#define TT_Detect_GPIO_Port GPIOA
#define _12V_ENDO1_ON_Pin GPIO_PIN_0
#define _12V_ENDO1_ON_GPIO_Port GPIOJ
#define DB7_Pin GPIO_PIN_10
#define DB7_GPIO_Port GPIOE
#define _12V_FUSE_ON_Pin GPIO_PIN_8
#define _12V_FUSE_ON_GPIO_Port GPIOJ
#define STAT_12V_ForceS_Pin GPIO_PIN_7
#define STAT_12V_ForceS_GPIO_Port GPIOJ
#define _12V_ForceS_ON_Pin GPIO_PIN_6
#define _12V_ForceS_ON_GPIO_Port GPIOJ
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOH
#define SDRAM_nWE_Pin GPIO_PIN_5
#define SDRAM_nWE_GPIO_Port GPIOH
#define STAT_12V_ENDO1_Pin GPIO_PIN_1
#define STAT_12V_ENDO1_GPIO_Port GPIOJ
#define AB7_Pin GPIO_PIN_13
#define AB7_GPIO_Port GPIOF
#define AB8_Pin GPIO_PIN_14
#define AB8_GPIO_Port GPIOF
#define DB6_Pin GPIO_PIN_9
#define DB6_GPIO_Port GPIOE
#define DB8_Pin GPIO_PIN_11
#define DB8_GPIO_Port GPIOE
#define DISCONN_CAN_COL_Pin GPIO_PIN_10
#define DISCONN_CAN_COL_GPIO_Port GPIOB
#define DB18_Pin GPIO_PIN_10
#define DB18_GPIO_Port GPIOH
#define DB19_Pin GPIO_PIN_11
#define DB19_GPIO_Port GPIOH
#define DB1_Pin GPIO_PIN_15
#define DB1_GPIO_Port GPIOD
#define DB0_Pin GPIO_PIN_14
#define DB0_GPIO_Port GPIOD
#define ADC_40V_TT_Pin GPIO_PIN_2
#define ADC_40V_TT_GPIO_Port GPIOC
#define ADC_40V_COL_Pin GPIO_PIN_3
#define ADC_40V_COL_GPIO_Port GPIOC
#define ADC_5V_Pin GPIO_PIN_6
#define ADC_5V_GPIO_Port GPIOA
#define ADIS_MOSI_Pin GPIO_PIN_7
#define ADIS_MOSI_GPIO_Port GPIOA
#define nREED_REF_Pin GPIO_PIN_2
#define nREED_REF_GPIO_Port GPIOB
#define AB6_Pin GPIO_PIN_12
#define AB6_GPIO_Port GPIOF
#define AB9_Pin GPIO_PIN_15
#define AB9_GPIO_Port GPIOF
#define DB9_Pin GPIO_PIN_12
#define DB9_GPIO_Port GPIOE
#define DB12_Pin GPIO_PIN_15
#define DB12_GPIO_Port GPIOE
#define STAT_12V_WedgeS_Pin GPIO_PIN_5
#define STAT_12V_WedgeS_GPIO_Port GPIOJ
#define DB17_Pin GPIO_PIN_9
#define DB17_GPIO_Port GPIOH
#define DB20_Pin GPIO_PIN_12
#define DB20_GPIO_Port GPIOH
#define EN_CAN_COL_Pin GPIO_PIN_11
#define EN_CAN_COL_GPIO_Port GPIOD
#define ADC_12V5_Pin GPIO_PIN_0
#define ADC_12V5_GPIO_Port GPIOA
#define ADC_12V_RC_Pin GPIO_PIN_1
#define ADC_12V_RC_GPIO_Port GPIOA
#define DAC_ENDOCURRENT_Pin GPIO_PIN_5
#define DAC_ENDOCURRENT_GPIO_Port GPIOA
#define ADC_16V_Pin GPIO_PIN_4
#define ADC_16V_GPIO_Port GPIOC
#define TXLBEN_CAN_COL_Pin GPIO_PIN_1
#define TXLBEN_CAN_COL_GPIO_Port GPIOB
#define _12V_ENDO2_ON_Pin GPIO_PIN_2
#define _12V_ENDO2_ON_GPIO_Port GPIOJ
#define SDRAM_nRAS_Pin GPIO_PIN_11
#define SDRAM_nRAS_GPIO_Port GPIOF
#define AB10_Pin GPIO_PIN_0
#define AB10_GPIO_Port GPIOG
#define DB5_Pin GPIO_PIN_8
#define DB5_GPIO_Port GPIOE
#define DB10_Pin GPIO_PIN_13
#define DB10_GPIO_Port GPIOE
#define nSDRAM_nCS_Pin GPIO_PIN_6
#define nSDRAM_nCS_GPIO_Port GPIOH
#define DB16_Pin GPIO_PIN_8
#define DB16_GPIO_Port GPIOH
#define RXD_CC_Pin GPIO_PIN_12
#define RXD_CC_GPIO_Port GPIOB
#define RXD_DBG_Pin GPIO_PIN_15
#define RXD_DBG_GPIO_Port GPIOB
#define DB15_Pin GPIO_PIN_10
#define DB15_GPIO_Port GPIOD
#define DB14_Pin GPIO_PIN_9
#define DB14_GPIO_Port GPIOD
#define DISCONN_CAN_TT_Pin GPIO_PIN_3
#define DISCONN_CAN_TT_GPIO_Port GPIOA
#define EN_CAN_TT_Pin GPIO_PIN_4
#define EN_CAN_TT_GPIO_Port GPIOA
#define nRST_ISM_Pin GPIO_PIN_5
#define nRST_ISM_GPIO_Port GPIOC
#define DIAG_CAN_COL_Pin GPIO_PIN_0
#define DIAG_CAN_COL_GPIO_Port GPIOB
#define STAT_12V_ENDO2_Pin GPIO_PIN_3
#define STAT_12V_ENDO2_GPIO_Port GPIOJ
#define _12V_WedgeS_ON_Pin GPIO_PIN_4
#define _12V_WedgeS_ON_GPIO_Port GPIOJ
#define DB4_Pin GPIO_PIN_7
#define DB4_GPIO_Port GPIOE
#define DB11_Pin GPIO_PIN_14
#define DB11_GPIO_Port GPIOE
#define SDRAM_CKE_Pin GPIO_PIN_7
#define SDRAM_CKE_GPIO_Port GPIOH
#define TXD_CAN_COL_Pin GPIO_PIN_13
#define TXD_CAN_COL_GPIO_Port GPIOB
#define TXD_DBG_Pin GPIO_PIN_14
#define TXD_DBG_GPIO_Port GPIOB
#define DB13_Pin GPIO_PIN_8
#define DB13_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
