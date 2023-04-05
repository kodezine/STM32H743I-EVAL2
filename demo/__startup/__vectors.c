#include <stdint.h>
#include "stm32h743xx.h"
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6100100)
    #include "__vectors_ac6.h"
#elif defined(__GNUC__)
    #if defined(__clang__)
        #include "__vectors_llvm.h"
    #else
        //#include "__vectors_gcc.h"
    #endif
#endif
#include "system_ARMCM7.h"
#include "cmsis_compiler.h"

/******************************************************************************
 * @file     startup_<Device>.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device <Device>
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak));
void MemManage_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler (void) __attribute__((weak, alias("Default_Handler")));

/* Add your device specific interrupt handler */
/*---------------------------------------------------------------------------
  ISR
 *---------------------------------------------------------------------------*/
void WWDG_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*  16 Window WatchDog interrupt ( wwdg1_it) */
void PVD_AVD_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*  17 PVD/AVD through EXTI Line detection */
void TAMP_STAMP_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*  18 Tamper and TimeStamps through the EXTI line */
void RTC_WKUP_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); /*  19 RTC Wakeup through the EXTI line */
void FLASH_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*  20 FLASH */
void RCC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*  21 RCC */
void EXTI0_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*  22 EXTI Line0 */
void EXTI1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*  23 EXTI Line1 */
void EXTI2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    EXTI Line2 */
void EXTI3_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    EXTI Line3 */
void EXTI4_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    EXTI Line4 */
void DMA1_Stream0_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 0 */
void DMA1_Stream1_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 1 */
void DMA1_Stream2_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 2 */
void DMA1_Stream3_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 3 */
void DMA1_Stream4_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 4 */
void DMA1_Stream5_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 5 */
void DMA1_Stream6_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream 6 */
void ADC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    ADC1, ADC2 */
void FDCAN1_IT0_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    FDCAN1 interrupt line 0 */
void FDCAN2_IT0_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    FDCAN2 interrupt line 0 */
void FDCAN1_IT1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    FDCAN1 interrupt line 1 */
void FDCAN2_IT1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    FDCAN2 interrupt line 1 */
void EXTI9_5_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    External Line[9:5]s */
void TIM1_BRK_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM1 Break interrupt */
void TIM1_UP_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM1 Update Interrupt */
void TIM1_TRG_COM_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM1 Trigger and Commutation Interrupt */
void TIM1_CC_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM1 Capture Compare */
void TIM2_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM2 */
void TIM3_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM3 */
void TIM4_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM4 */
void I2C1_EV_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C1 Event */
void I2C1_ER_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C1 Error */
void I2C2_EV_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C2 Event */
void I2C2_ER_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C2 Error */
void SPI1_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI1 */
void SPI2_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI2 */
void USART1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USART1 */
void USART2_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USART2 */
void USART3_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USART3 */
void EXTI15_10_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); /*    External Line[15:10] */
void RTC_Alarm_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); /*    RTC Alarm (A and B) through EXTI Line */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void TIM8_BRK_TIM12_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM8 Break Interrupt and TIM12 global interrupt */
void TIM8_UP_TIM13_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM8 Update Interrupt and TIM13 global interrupt */
void TIM8_TRG_COM_TIM14_IRQHandler  (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
void TIM8_CC_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM8 Capture Compare Interrupt */
void DMA1_Stream7_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA1 Stream7 */
void FMC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    FMC */
void SDMMC1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    SDMMC1 */
void TIM5_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM5 */
void SPI3_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI3 */
void UART4_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    UART4 */
void UART5_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    UART5 */
void TIM6_DAC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM6 and DAC1&2 underrun errors */
void TIM7_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM7 */
void DMA2_Stream0_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 0 */
void DMA2_Stream1_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 1 */
void DMA2_Stream2_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 2 */
void DMA2_Stream3_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 3 */
void DMA2_Stream4_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 4 */
void ETH_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    Ethernet */
void ETH_WKUP_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); /*    Ethernet Wakeup through EXTI line */
void FDCAN_CAL_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); /*    FDCAN calibration unit interrupt */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void DMA2_Stream5_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 5 */
void DMA2_Stream6_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 6 */
void DMA2_Stream7_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2 Stream 7 */
void USART6_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USART6 */
void I2C3_EV_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C3 event */
void I2C3_ER_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C3 error */
void OTG_HS_EP1_OUT_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG HS End Point 1 Out */
void OTG_HS_EP1_IN_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG HS End Point 1 In */
void OTG_HS_WKUP_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG HS Wakeup through EXTI */
void OTG_HS_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG HS */
void DCMI_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    DCMI */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void RNG_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    Rng */
void FPU_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    FPU */
void UART7_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    UART7 */
void UART8_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    UART8 */
void SPI4_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI4 */
void SPI5_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI5 */
void SPI6_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SPI6 */
void SAI1_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SAI1 */
void LTDC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    LTDC */
void LTDC_ER_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    LTDC error */
void DMA2D_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    DMA2D */
void SAI2_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SAI2 */
void QUADSPI_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    QUADSPI */
void LPTIM1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    LPTIM1 */
void CEC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    HDMI_CEC */
void I2C4_EV_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C4 Event */
void I2C4_ER_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    I2C4 Error */
void SPDIF_RX_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); /*    SPDIF_RX */
void OTG_FS_EP1_OUT_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG FS End Point 1 Out */
void OTG_FS_EP1_IN_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG FS End Point 1 In */
void OTG_FS_WKUP_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG FS Wakeup through EXTI */
void OTG_FS_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    USB OTG FS */
void DMAMUX1_OVR_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DMAMUX1 Overrun interrupt */
void HRTIM1_Master_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Master Timer global Interrupts */
void HRTIM1_TIMA_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Timer A global Interrupt */
void HRTIM1_TIMB_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Timer B global Interrupt */
void HRTIM1_TIMC_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Timer C global Interrupt */
void HRTIM1_TIMD_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Timer D global Interrupt */
void HRTIM1_TIME_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Timer E global Interrupt */
void HRTIM1_FLT_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    HRTIM Fault global Interrupt */
void DFSDM1_FLT0_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DFSDM Filter0 Interrupt */
void DFSDM1_FLT1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DFSDM Filter1 Interrupt */
void DFSDM1_FLT2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DFSDM Filter2 Interrupt */
void DFSDM1_FLT3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DFSDM Filter3 Interrupt */
void SAI3_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SAI3 global Interrupt */
void SWPMI1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    Serial Wire Interface 1 global interrupt */
void TIM15_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM15 global Interrupt */
void TIM16_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM16 global Interrupt */
void TIM17_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    TIM17 global Interrupt */
void MDIOS_WKUP_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    MDIOS Wakeup  Interrupt */
void MDIOS_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    MDIOS global Interrupt */
void JPEG_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    JPEG global Interrupt */
void MDMA_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    MDMA global Interrupt */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void SDMMC2_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    SDMMC2 global Interrupt */
void HSEM1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    HSEM1 global Interrupt */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void ADC3_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    ADC3 global Interrupt */
void DMAMUX2_OVR_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); /*    DMAMUX Overrun interrupt */
void BDMA_Channel0_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 0 global Interrupt */
void BDMA_Channel1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 1 global Interrupt */
void BDMA_Channel2_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 2 global Interrupt */
void BDMA_Channel3_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 3 global Interrupt */
void BDMA_Channel4_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 4 global Interrupt */
void BDMA_Channel5_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 5 global Interrupt */
void BDMA_Channel6_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 6 global Interrupt */
void BDMA_Channel7_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); /*    BDMA Channel 7 global Interrupt */
void COMP1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); /*    COMP1 global Interrupt */
void LPTIM2_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    LP TIM2 global interrupt */
void LPTIM3_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    LP TIM3 global interrupt */
void LPTIM4_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    LP TIM4 global interrupt */
void LPTIM5_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); /*    LP TIM5 global interrupt */
void LPUART1_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); /*    LP UART1 interrupt */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void CRS_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    Clock Recovery Global Interrupt */
void ECC_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler"))); /*    ECC diagnostic Global Interrupt */
void SAI4_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); /*    SAI4 global interrupt */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
//void 0                            (void)   __attribute__((weak, alias("Default_Handler"))); /*    Reserved */
void WAKEUP_PIN_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); /*    Interrupt for all 6 wake-up pins */
/*-----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP)                 ,/*     Initial Stack Pointer */
    (VECTOR_TABLE_Type)&Reset_Handler                  ,/*     Reset Handler */
    (VECTOR_TABLE_Type)&NMI_Handler                    ,/* -14 NMI Handler */
    (VECTOR_TABLE_Type)&HardFault_Handler              ,/* -13 Hard Fault Handler */
    (VECTOR_TABLE_Type)&MemManage_Handler              ,/* -12 MPU Fault Handler */
    (VECTOR_TABLE_Type)&BusFault_Handler               ,/* -11 Bus Fault Handler */
    (VECTOR_TABLE_Type)&UsageFault_Handler             ,/* -10 Usage Fault Handler */
    (VECTOR_TABLE_Type)0                               ,/*  -9 Reserved */
    (VECTOR_TABLE_Type)0                               ,/*  -8 Reserved */
    (VECTOR_TABLE_Type)0                               ,/*  -7 Reserved */
    (VECTOR_TABLE_Type)0                               ,/*  -6 Reserved */
    (VECTOR_TABLE_Type)&SVC_Handler                    ,/*  -5 SVCall Handler */
    (VECTOR_TABLE_Type)&DebugMon_Handler               ,/*  -4 Debug Monitor Handler */
    (VECTOR_TABLE_Type)0                               ,/*  -3 Reserved */
    (VECTOR_TABLE_Type)&PendSV_Handler                 ,/*  -2 PendSV Handler */
    (VECTOR_TABLE_Type)&SysTick_Handler                ,/*  -1 SysTick Handler */


    (VECTOR_TABLE_Type)&WWDG_IRQHandler                ,/*  16 Window WatchDog interrupt ( wwdg1_it) */
    (VECTOR_TABLE_Type)&PVD_AVD_IRQHandler             ,/*  17 PVD/AVD through EXTI Line detection */
    (VECTOR_TABLE_Type)&TAMP_STAMP_IRQHandler          ,/*  18 Tamper and TimeStamps through the EXTI line */
    (VECTOR_TABLE_Type)&RTC_WKUP_IRQHandler            ,/*  19 RTC Wakeup through the EXTI line */
    (VECTOR_TABLE_Type)&FLASH_IRQHandler               ,/*  20 FLASH */
    (VECTOR_TABLE_Type)&RCC_IRQHandler                 ,/*  21 RCC */
    (VECTOR_TABLE_Type)&EXTI0_IRQHandler               ,/*  22 EXTI Line0 */
    (VECTOR_TABLE_Type)&EXTI1_IRQHandler               ,/*  23 EXTI Line1 */
    (VECTOR_TABLE_Type)&EXTI2_IRQHandler               ,/*    EXTI Line2 */
    (VECTOR_TABLE_Type)&EXTI3_IRQHandler               ,/*    EXTI Line3 */
    (VECTOR_TABLE_Type)&EXTI4_IRQHandler               ,/*    EXTI Line4 */
    (VECTOR_TABLE_Type)&DMA1_Stream0_IRQHandler        ,/*    DMA1 Stream 0 */
    (VECTOR_TABLE_Type)&DMA1_Stream1_IRQHandler        ,/*    DMA1 Stream 1 */
    (VECTOR_TABLE_Type)&DMA1_Stream2_IRQHandler        ,/*    DMA1 Stream 2 */
    (VECTOR_TABLE_Type)&DMA1_Stream3_IRQHandler        ,/*    DMA1 Stream 3 */
    (VECTOR_TABLE_Type)&DMA1_Stream4_IRQHandler        ,/*    DMA1 Stream 4 */
    (VECTOR_TABLE_Type)&DMA1_Stream5_IRQHandler        ,/*    DMA1 Stream 5 */
    (VECTOR_TABLE_Type)&DMA1_Stream6_IRQHandler        ,/*    DMA1 Stream 6 */
    (VECTOR_TABLE_Type)&ADC_IRQHandler                 ,/*    ADC1, ADC2 */
    (VECTOR_TABLE_Type)&FDCAN1_IT0_IRQHandler          ,/*    FDCAN1 interrupt line 0 */
    (VECTOR_TABLE_Type)&FDCAN2_IT0_IRQHandler          ,/*    FDCAN2 interrupt line 0 */
    (VECTOR_TABLE_Type)&FDCAN1_IT1_IRQHandler          ,/*    FDCAN1 interrupt line 1 */
    (VECTOR_TABLE_Type)&FDCAN2_IT1_IRQHandler          ,/*    FDCAN2 interrupt line 1 */
    (VECTOR_TABLE_Type)&EXTI9_5_IRQHandler             ,/*    External Line[9:5]s */
    (VECTOR_TABLE_Type)&TIM1_BRK_IRQHandler            ,/*    TIM1 Break interrupt */
    (VECTOR_TABLE_Type)&TIM1_UP_IRQHandler             ,/*    TIM1 Update Interrupt */
    (VECTOR_TABLE_Type)&TIM1_TRG_COM_IRQHandler        ,/*    TIM1 Trigger and Commutation Interrupt */
    (VECTOR_TABLE_Type)&TIM1_CC_IRQHandler             ,/*    TIM1 Capture Compare */
    (VECTOR_TABLE_Type)&TIM2_IRQHandler                ,/*    TIM2 */
    (VECTOR_TABLE_Type)&TIM3_IRQHandler                ,/*    TIM3 */
    (VECTOR_TABLE_Type)&TIM4_IRQHandler                ,/*    TIM4 */
    (VECTOR_TABLE_Type)&I2C1_EV_IRQHandler             ,/*    I2C1 Event */
    (VECTOR_TABLE_Type)&I2C1_ER_IRQHandler             ,/*    I2C1 Error */
    (VECTOR_TABLE_Type)&I2C2_EV_IRQHandler             ,/*    I2C2 Event */
    (VECTOR_TABLE_Type)&I2C2_ER_IRQHandler             ,/*    I2C2 Error */
    (VECTOR_TABLE_Type)&SPI1_IRQHandler                ,/*    SPI1 */
    (VECTOR_TABLE_Type)&SPI2_IRQHandler                ,/*    SPI2 */
    (VECTOR_TABLE_Type)&USART1_IRQHandler              ,/*    USART1 */
    (VECTOR_TABLE_Type)&USART2_IRQHandler              ,/*    USART2 */
    (VECTOR_TABLE_Type)&USART3_IRQHandler              ,/*    USART3 */
    (VECTOR_TABLE_Type)&EXTI15_10_IRQHandler           ,/*    External Line[15:10] */
    (VECTOR_TABLE_Type)&RTC_Alarm_IRQHandler           ,/*    RTC Alarm (A and B) through EXTI Line */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&TIM8_BRK_TIM12_IRQHandler      ,/*    TIM8 Break Interrupt and TIM12 global interrupt */
    (VECTOR_TABLE_Type)&TIM8_UP_TIM13_IRQHandler       ,/*    TIM8 Update Interrupt and TIM13 global interrupt */
    (VECTOR_TABLE_Type)&TIM8_TRG_COM_TIM14_IRQHandler  ,/*    TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    (VECTOR_TABLE_Type)&TIM8_CC_IRQHandler             ,/*    TIM8 Capture Compare Interrupt */
    (VECTOR_TABLE_Type)&DMA1_Stream7_IRQHandler        ,/*    DMA1 Stream7 */
    (VECTOR_TABLE_Type)&FMC_IRQHandler                 ,/*    FMC */
    (VECTOR_TABLE_Type)&SDMMC1_IRQHandler              ,/*    SDMMC1 */
    (VECTOR_TABLE_Type)&TIM5_IRQHandler                ,/*    TIM5 */
    (VECTOR_TABLE_Type)&SPI3_IRQHandler                ,/*    SPI3 */
    (VECTOR_TABLE_Type)&UART4_IRQHandler               ,/*    UART4 */
    (VECTOR_TABLE_Type)&UART5_IRQHandler               ,/*    UART5 */
    (VECTOR_TABLE_Type)&TIM6_DAC_IRQHandler            ,/*    TIM6 and DAC1&2 underrun errors */
    (VECTOR_TABLE_Type)&TIM7_IRQHandler                ,/*    TIM7 */
    (VECTOR_TABLE_Type)&DMA2_Stream0_IRQHandler        ,/*    DMA2 Stream 0 */
    (VECTOR_TABLE_Type)&DMA2_Stream1_IRQHandler        ,/*    DMA2 Stream 1 */
    (VECTOR_TABLE_Type)&DMA2_Stream2_IRQHandler        ,/*    DMA2 Stream 2 */
    (VECTOR_TABLE_Type)&DMA2_Stream3_IRQHandler        ,/*    DMA2 Stream 3 */
    (VECTOR_TABLE_Type)&DMA2_Stream4_IRQHandler        ,/*    DMA2 Stream 4 */
    (VECTOR_TABLE_Type)&ETH_IRQHandler                 ,/*    Ethernet */
    (VECTOR_TABLE_Type)&ETH_WKUP_IRQHandler            ,/*    Ethernet Wakeup through EXTI line */
    (VECTOR_TABLE_Type)&FDCAN_CAL_IRQHandler           ,/*    FDCAN calibration unit interrupt */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&DMA2_Stream5_IRQHandler        ,/*    DMA2 Stream 5 */
    (VECTOR_TABLE_Type)&DMA2_Stream6_IRQHandler        ,/*    DMA2 Stream 6 */
    (VECTOR_TABLE_Type)&DMA2_Stream7_IRQHandler        ,/*    DMA2 Stream 7 */
    (VECTOR_TABLE_Type)&USART6_IRQHandler              ,/*    USART6 */
    (VECTOR_TABLE_Type)&I2C3_EV_IRQHandler             ,/*    I2C3 event */
    (VECTOR_TABLE_Type)&I2C3_ER_IRQHandler             ,/*    I2C3 error */
    (VECTOR_TABLE_Type)&OTG_HS_EP1_OUT_IRQHandler      ,/*    USB OTG HS End Point 1 Out */
    (VECTOR_TABLE_Type)&OTG_HS_EP1_IN_IRQHandler       ,/*    USB OTG HS End Point 1 In */
    (VECTOR_TABLE_Type)&OTG_HS_WKUP_IRQHandler         ,/*    USB OTG HS Wakeup through EXTI */
    (VECTOR_TABLE_Type)&OTG_HS_IRQHandler              ,/*    USB OTG HS */
    (VECTOR_TABLE_Type)&DCMI_IRQHandler                ,/*    DCMI */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&RNG_IRQHandler                 ,/*    Rng */
    (VECTOR_TABLE_Type)&FPU_IRQHandler                 ,/*    FPU */
    (VECTOR_TABLE_Type)&UART7_IRQHandler               ,/*    UART7 */
    (VECTOR_TABLE_Type)&UART8_IRQHandler               ,/*    UART8 */
    (VECTOR_TABLE_Type)&SPI4_IRQHandler                ,/*    SPI4 */
    (VECTOR_TABLE_Type)&SPI5_IRQHandler                ,/*    SPI5 */
    (VECTOR_TABLE_Type)&SPI6_IRQHandler                ,/*    SPI6 */
    (VECTOR_TABLE_Type)&SAI1_IRQHandler                ,/*    SAI1 */
    (VECTOR_TABLE_Type)&LTDC_IRQHandler                ,/*    LTDC */
    (VECTOR_TABLE_Type)&LTDC_ER_IRQHandler             ,/*    LTDC error */
    (VECTOR_TABLE_Type)&DMA2D_IRQHandler               ,/*    DMA2D */
    (VECTOR_TABLE_Type)&SAI2_IRQHandler                ,/*    SAI2 */
    (VECTOR_TABLE_Type)&QUADSPI_IRQHandler             ,/*    QUADSPI */
    (VECTOR_TABLE_Type)&LPTIM1_IRQHandler              ,/*    LPTIM1 */
    (VECTOR_TABLE_Type)&CEC_IRQHandler                 ,/*    HDMI_CEC */
    (VECTOR_TABLE_Type)&I2C4_EV_IRQHandler             ,/*    I2C4 Event */
    (VECTOR_TABLE_Type)&I2C4_ER_IRQHandler             ,/*    I2C4 Error */
    (VECTOR_TABLE_Type)&SPDIF_RX_IRQHandler            ,/*    SPDIF_RX */
    (VECTOR_TABLE_Type)&OTG_FS_EP1_OUT_IRQHandler      ,/*    USB OTG FS End Point 1 Out */
    (VECTOR_TABLE_Type)&OTG_FS_EP1_IN_IRQHandler       ,/*    USB OTG FS End Point 1 In */
    (VECTOR_TABLE_Type)&OTG_FS_WKUP_IRQHandler         ,/*    USB OTG FS Wakeup through EXTI */
    (VECTOR_TABLE_Type)&OTG_FS_IRQHandler              ,/*    USB OTG FS */
    (VECTOR_TABLE_Type)&DMAMUX1_OVR_IRQHandler         ,/*    DMAMUX1 Overrun interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_Master_IRQHandler       ,/*    HRTIM Master Timer global Interrupts */
    (VECTOR_TABLE_Type)&HRTIM1_TIMA_IRQHandler         ,/*    HRTIM Timer A global Interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_TIMB_IRQHandler         ,/*    HRTIM Timer B global Interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_TIMC_IRQHandler         ,/*    HRTIM Timer C global Interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_TIMD_IRQHandler         ,/*    HRTIM Timer D global Interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_TIME_IRQHandler         ,/*    HRTIM Timer E global Interrupt */
    (VECTOR_TABLE_Type)&HRTIM1_FLT_IRQHandler          ,/*    HRTIM Fault global Interrupt */
    (VECTOR_TABLE_Type)&DFSDM1_FLT0_IRQHandler         ,/*    DFSDM Filter0 Interrupt */
    (VECTOR_TABLE_Type)&DFSDM1_FLT1_IRQHandler         ,/*    DFSDM Filter1 Interrupt */
    (VECTOR_TABLE_Type)&DFSDM1_FLT2_IRQHandler         ,/*    DFSDM Filter2 Interrupt */
    (VECTOR_TABLE_Type)&DFSDM1_FLT3_IRQHandler         ,/*    DFSDM Filter3 Interrupt */
    (VECTOR_TABLE_Type)&SAI3_IRQHandler                ,/*    SAI3 global Interrupt */
    (VECTOR_TABLE_Type)&SWPMI1_IRQHandler              ,/*    Serial Wire Interface 1 global interrupt */
    (VECTOR_TABLE_Type)&TIM15_IRQHandler               ,/*    TIM15 global Interrupt */
    (VECTOR_TABLE_Type)&TIM16_IRQHandler               ,/*    TIM16 global Interrupt */
    (VECTOR_TABLE_Type)&TIM17_IRQHandler               ,/*    TIM17 global Interrupt */
    (VECTOR_TABLE_Type)&MDIOS_WKUP_IRQHandler          ,/*    MDIOS Wakeup  Interrupt */
    (VECTOR_TABLE_Type)&MDIOS_IRQHandler               ,/*    MDIOS global Interrupt */
    (VECTOR_TABLE_Type)&JPEG_IRQHandler                ,/*    JPEG global Interrupt */
    (VECTOR_TABLE_Type)&MDMA_IRQHandler                ,/*    MDMA global Interrupt */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&SDMMC2_IRQHandler              ,/*    SDMMC2 global Interrupt */
    (VECTOR_TABLE_Type)&HSEM1_IRQHandler               ,/*    HSEM1 global Interrupt */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&ADC3_IRQHandler                ,/*    ADC3 global Interrupt */
    (VECTOR_TABLE_Type)&DMAMUX2_OVR_IRQHandler         ,/*    DMAMUX Overrun interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel0_IRQHandler       ,/*    BDMA Channel 0 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel1_IRQHandler       ,/*    BDMA Channel 1 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel2_IRQHandler       ,/*    BDMA Channel 2 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel3_IRQHandler       ,/*    BDMA Channel 3 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel4_IRQHandler       ,/*    BDMA Channel 4 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel5_IRQHandler       ,/*    BDMA Channel 5 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel6_IRQHandler       ,/*    BDMA Channel 6 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA_Channel7_IRQHandler       ,/*    BDMA Channel 7 global Interrupt */
    (VECTOR_TABLE_Type)&COMP1_IRQHandler               ,/*    COMP1 global Interrupt */
    (VECTOR_TABLE_Type)&LPTIM2_IRQHandler              ,/*    LP TIM2 global interrupt */
    (VECTOR_TABLE_Type)&LPTIM3_IRQHandler              ,/*    LP TIM3 global interrupt */
    (VECTOR_TABLE_Type)&LPTIM4_IRQHandler              ,/*    LP TIM4 global interrupt */
    (VECTOR_TABLE_Type)&LPTIM5_IRQHandler              ,/*    LP TIM5 global interrupt */
    (VECTOR_TABLE_Type)&LPUART1_IRQHandler             ,/*    LP UART1 interrupt */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&CRS_IRQHandler                 ,/*    Clock Recovery Global Interrupt */
    (VECTOR_TABLE_Type)&ECC_IRQHandler                 ,/*    ECC diagnostic Global Interrupt */
    (VECTOR_TABLE_Type)&SAI4_IRQHandler                ,/*    SAI4 global interrupt */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)0                               ,/*    Reserved */
    (VECTOR_TABLE_Type)&WAKEUP_PIN_IRQHandler          ,/*    Interrupt for all 6 wake-up pins */

};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP((uint32_t)(&__INITIAL_SP));

/* ToDo: Initialize stack limit register for Armv8-M Main Extension based processors*/
//    __set_MSP((uint32_t)(&__STACK_LIMIT));
//    __set_PSP((uint32_t)(&__STACK_LIMIT));

/* ToDo: Add stack sealing for Armv8-M based processors */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();      /* CMSIS System Initialization */
    __PROGRAM_START(); /* Enter PreMain (C library entry point) */
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
    while (1)
        ;
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
