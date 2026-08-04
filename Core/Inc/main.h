/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define FS_2_Pin GPIO_PIN_2
#define FS_2_GPIO_Port GPIOE
#define LED_FS_3_Pin GPIO_PIN_5
#define LED_FS_3_GPIO_Port GPIOE
#define FS_3_Pin GPIO_PIN_6
#define FS_3_GPIO_Port GPIOE
#define FS_8_Pin GPIO_PIN_13
#define FS_8_GPIO_Port GPIOC
#define LED_FS_8_Pin GPIO_PIN_14
#define LED_FS_8_GPIO_Port GPIOC
#define FS_4_Pin GPIO_PIN_15
#define FS_4_GPIO_Port GPIOC
#define LED_FS_4_Pin GPIO_PIN_0
#define LED_FS_4_GPIO_Port GPIOF
#define FS_9_Pin GPIO_PIN_1
#define FS_9_GPIO_Port GPIOF
#define LED_FS_9_Pin GPIO_PIN_2
#define LED_FS_9_GPIO_Port GPIOF
#define LED_FS_5_Pin GPIO_PIN_7
#define LED_FS_5_GPIO_Port GPIOF
#define FS_5_Pin GPIO_PIN_8
#define FS_5_GPIO_Port GPIOF
#define LED_FS_10_Pin GPIO_PIN_9
#define LED_FS_10_GPIO_Port GPIOF
#define FS_10_Pin GPIO_PIN_10
#define FS_10_GPIO_Port GPIOF
#define CODEC_SDIN_Pin GPIO_PIN_1
#define CODEC_SDIN_GPIO_Port GPIOC
#define CODEC_SDOUT_Pin GPIO_PIN_2
#define CODEC_SDOUT_GPIO_Port GPIOC
#define ENC4_A_Pin GPIO_PIN_0
#define ENC4_A_GPIO_Port GPIOA
#define ENC4_B_Pin GPIO_PIN_1
#define ENC4_B_GPIO_Port GPIOA
#define ENC4_SW_Pin GPIO_PIN_2
#define ENC4_SW_GPIO_Port GPIOA
#define ENC3_A_Pin GPIO_PIN_6
#define ENC3_A_GPIO_Port GPIOA
#define ENC3_B_Pin GPIO_PIN_7
#define ENC3_B_GPIO_Port GPIOA
#define ENC3_SW_Pin GPIO_PIN_4
#define ENC3_SW_GPIO_Port GPIOC
#define CODEC_SCL_Pin GPIO_PIN_14
#define CODEC_SCL_GPIO_Port GPIOF
#define CODEC_SDA_Pin GPIO_PIN_15
#define CODEC_SDA_GPIO_Port GPIOF
#define CODEC_NRST_Pin GPIO_PIN_1
#define CODEC_NRST_GPIO_Port GPIOG
#define ENC2_A_Pin GPIO_PIN_9
#define ENC2_A_GPIO_Port GPIOE
#define ENC2_B_Pin GPIO_PIN_11
#define ENC2_B_GPIO_Port GPIOE
#define ENC2_SW_Pin GPIO_PIN_12
#define ENC2_SW_GPIO_Port GPIOE
#define CODEC_SCLK_Pin GPIO_PIN_10
#define CODEC_SCLK_GPIO_Port GPIOB
#define CODEC_LRCK_Pin GPIO_PIN_12
#define CODEC_LRCK_GPIO_Port GPIOB
#define ENC1_SW_Pin GPIO_PIN_11
#define ENC1_SW_GPIO_Port GPIOD
#define ENC1_A_Pin GPIO_PIN_12
#define ENC1_A_GPIO_Port GPIOD
#define ENC1_B_Pin GPIO_PIN_13
#define ENC1_B_GPIO_Port GPIOD
#define CODEC_MCLK_Pin GPIO_PIN_6
#define CODEC_MCLK_GPIO_Port GPIOC
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_N_Pin GPIO_PIN_11
#define USB_N_GPIO_Port GPIOA
#define USB_P_Pin GPIO_PIN_12
#define USB_P_GPIO_Port GPIOA
#define MCU_SWDIO_Pin GPIO_PIN_13
#define MCU_SWDIO_GPIO_Port GPIOA
#define MCU_SWCLK_Pin GPIO_PIN_14
#define MCU_SWCLK_GPIO_Port GPIOA
#define LCD_LED_Pin GPIO_PIN_15
#define LCD_LED_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_10
#define LCD_CS_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_11
#define SD_CS_GPIO_Port GPIOC
#define LCD_SCK_Pin GPIO_PIN_12
#define LCD_SCK_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_0
#define LCD_RST_GPIO_Port GPIOD
#define TOUCH_CS_Pin GPIO_PIN_1
#define TOUCH_CS_GPIO_Port GPIOD
#define TOUCH_IRQ_Pin GPIO_PIN_11
#define TOUCH_IRQ_GPIO_Port GPIOG
#define LCD_MISO_Pin GPIO_PIN_12
#define LCD_MISO_GPIO_Port GPIOG
#define LCD_DC_Pin GPIO_PIN_13
#define LCD_DC_GPIO_Port GPIOG
#define LCD_MOSI_Pin GPIO_PIN_14
#define LCD_MOSI_GPIO_Port GPIOG
#define MCU_SWO_Pin GPIO_PIN_3
#define MCU_SWO_GPIO_Port GPIOB
#define LED_FS_1_Pin GPIO_PIN_5
#define LED_FS_1_GPIO_Port GPIOB
#define LED_FS_6_Pin GPIO_PIN_6
#define LED_FS_6_GPIO_Port GPIOB
#define FS_6_Pin GPIO_PIN_7
#define FS_6_GPIO_Port GPIOB
#define LED_FS_7_Pin GPIO_PIN_8
#define LED_FS_7_GPIO_Port GPIOB
#define FS_1_Pin GPIO_PIN_9
#define FS_1_GPIO_Port GPIOB
#define FS_7_Pin GPIO_PIN_0
#define FS_7_GPIO_Port GPIOE
#define LED_FS_2_Pin GPIO_PIN_1
#define LED_FS_2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
