/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void sigleLed_on(int numLed){
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, i=0, k=0, l=0, m=0, n=0;
	switch(numLed){
	case 1:
		a=1; b=0; c=0; d=0; e=0; f=0; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 2:
		a=0; b=1; c=0; d=0; e=0; f=0; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 3:
		a=0; b=0; c=1; d=0; e=0; f=0; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 4:
		a=0; b=0; c=0; d=1; e=0; f=0; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 5:
		a=0; b=0; c=0; d=0; e=1; f=0; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 6:
		a=0; b=0; c=0; d=0; e=0; f=1; g=0; i=0; k=0; l=0; m=0; n=0;
		break;
	case 7:
		a=0; b=0; c=0; d=0; e=0; f=0; g=1; i=0; k=0; l=0; m=0; n=0;
		break;
	case 8:
		a=0; b=0; c=0; d=0; e=0; f=0; g=0; i=1; k=0; l=0; m=0; n=0;
		break;
	case 9:
		a=0; b=0; c=0; d=0; e=0; f=0; g=0; i=0; k=1; l=0; m=0; n=0;
		break;
	case 10:
		a=0; b=0; c=0; d=0; e=0; f=0; g=0; i=0; k=0; l=1; m=0; n=0;
		break;
	case 11:
		a=0; b=0; c=0; d=0; e=0; f=0; g=0; i=0; k=0; l=0; m=1; n=0;
		break;
	case 12:
		a=0; b=0; c=0; d=0; e=0; f=0; g=0; i=0; k=0; l=0; m=0; n=1;
		break;
	}
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, a);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, b);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, c);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, d);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, e);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, f);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, g);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, i);
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, k);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, l);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, m);
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, n);
}
void sequenceClock(int counter){
	if(counter==0){sigleLed_on(12);}
	else if(counter==11){sigleLed_on(11);}
	else if(counter==10){sigleLed_on(10);}
	else if(counter==9){sigleLed_on(9);}
	else if(counter==8){sigleLed_on(8);}
	else if(counter==7){sigleLed_on(7);}
	else if(counter==6){sigleLed_on(6);}
	else if(counter==5){sigleLed_on(5);}
	else if(counter==4){sigleLed_on(4);}
	else if(counter==3){sigleLed_on(3);}
	else if(counter==2){sigleLed_on(2);}
	else if(counter==1){sigleLed_on(1);}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int t = 0;
  while (1)
  {
	  sequenceClock(t);
	  t++;
	  if(t>=12) t=0;
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin|LED11_Pin|LED12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin LED7_Pin LED8_Pin
                           LED9_Pin LED10_Pin LED11_Pin LED12_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin|LED11_Pin|LED12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
