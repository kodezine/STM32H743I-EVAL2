/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PA15 (JTDI)   ------> DEBUG_JTDI
     PB4 (NJTRST)   ------> DEBUG_JTRST
     PA14 (JTCK/SWCLK)   ------> DEBUG_JTCK-SWCLK
     PC15-OSC32_OUT (OSC32_OUT)   ------> RCC_OSC32_OUT
     PC14-OSC32_IN (OSC32_IN)   ------> RCC_OSC32_IN
     PB3 (JTDO/TRACESWO)   ------> DEBUG_JTDO-SWO
     PA13 (JTMS/SWDIO)   ------> DEBUG_JTMS-SWDIO
     PH1-OSC_OUT (PH1)   ------> RCC_OSC_OUT
     PH0-OSC_IN (PH0)   ------> RCC_OSC_IN
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, TX_ISM_EN_BackUp_Pin|IR1_Enable_Pin|ISM_nBOOTLOADER_BackUp_Pin|IR2_Enable_Pin
                          |EN_CAN_COL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, nSHDN_CC_Pin|DISCONN_CAN_COL_Pin|TXLBEN_CAN_COL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, WDRESET_Pin|TE_485_RC_Pin|TXLBEN_CAN_TT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOJ, _5V_CC_ON_Pin|_5V_ON_Pin|_12V_RC_ON_Pin|_12V_ENDO1_ON_Pin
                          |_12V_FUSE_ON_Pin|_12V_ForceS_ON_Pin|_12V_ENDO2_ON_Pin|_12V_WedgeS_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, TX_ISM_EN_Pin|nRST_ISM_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ISM_nBOOTLOADER_GPIO_Port, ISM_nBOOTLOADER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOK, ISM_3V3_ON_Pin|_3V_CC_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DISCONN_CAN_TT_Pin|EN_CAN_TT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PKPin PKPin PKPin PKPin */
  GPIO_InitStruct.Pin = nIR1_IN_Pin|STAT_3V_CC_Pin|STAT_3V3_ISM_Pin|nIR2_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin */
  GPIO_InitStruct.Pin = TX_ISM_EN_BackUp_Pin|IR1_Enable_Pin|ISM_nBOOTLOADER_BackUp_Pin|IR2_Enable_Pin
                          |EN_CAN_COL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PJPin PJPin PJPin PJPin
                           PJPin PJPin PJPin PJPin */
  GPIO_InitStruct.Pin = STAT_5V_CC_Pin|STAT_5V_Pin|STAT_12V_RC_ERROR_Pin|STAT_12V_FUSE_Pin
                          |STAT_12V_ForceS_Pin|STAT_12V_ENDO1_Pin|STAT_12V_WedgeS_Pin|STAT_12V_ENDO2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

  /*Configure GPIO pins : PE2 PE5 PE4 PE3
                           PE6 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_3
                          |GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PK6 PK1 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

  /*Configure GPIO pins : PG12 PG1 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = nSHDN_CC_Pin|DISCONN_CAN_COL_Pin|TXLBEN_CAN_COL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB8 PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = nRST_IN_Pin|DIO_WedgeS_Pin|TXLB_CAN_COL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = WDRESET_Pin|TE_485_RC_Pin|TXLBEN_CAN_TT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PJPin PJPin PJPin PJPin
                           PJPin PJPin PJPin PJPin */
  GPIO_InitStruct.Pin = _5V_CC_ON_Pin|_5V_ON_Pin|_12V_RC_ON_Pin|_12V_ENDO1_ON_Pin
                          |_12V_FUSE_ON_Pin|_12V_ForceS_ON_Pin|_12V_ENDO2_ON_Pin|_12V_WedgeS_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin
                           PAPin */
  GPIO_InitStruct.Pin = TXLB_CAN_TT_Pin|DIAG_CAN_TT_Pin|nREED_DIR_Pin|STATUS_40V_TT_Pin
                          |TT_Detect_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = TX_ISM_EN_Pin|nRST_ISM_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = ISM_nBOOTLOADER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ISM_nBOOTLOADER_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PI11 PI14 PI15 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pins : PIPin PIPin */
  GPIO_InitStruct.Pin = REED_DIR_CC_Pin|REED_REF_CC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pins : PKPin PKPin */
  GPIO_InitStruct.Pin = ISM_3V3_ON_Pin|_3V_CC_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

  /*Configure GPIO pin : PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PHPin PHPin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PH4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = nREED_REF_Pin|DIAG_CAN_COL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = DISCONN_CAN_TT_Pin|EN_CAN_TT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
