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


int matriz[4][4] = {
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}};

char v[3];






/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void piscaled();
void desligaled();
void ligabuzz();
void desligabuzz();
void TestaTeclado();
void AleatorizaPosicao();
void FimDeJogo(void);
void apertaTB();
int LeBotaoLinha();
char LeBotaoColuna();
void JogadaCerta();
void verifica();
void iniciaJogo();


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  while (1)
  {

//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);//Buzzer

	  iniciaJogo();



	  	}


}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PC14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Bot_o_Pin PA4 */
  GPIO_InitStruct.Pin = Bot_o_Pin|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA7 PA10 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB12
                           PB3 PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_12
                          |GPIO_PIN_3|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB11 PB6 PB7 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void piscaled(){


	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 1);//1
		 HAL_Delay(200);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);//2
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);//3
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);//4
		HAL_Delay(200);



	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);//5
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);//6
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);//7
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);//8
		 HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
}







void desligaled(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);//1
		HAL_Delay(200);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);//2
		HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);//3
		HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//4
		HAL_Delay(200);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);//5
		HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);//6
		HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);//7
		HAL_Delay(200);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);//8
		HAL_Delay(200);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0); //

}



int LeBotaoLinha(void)//Tem retorno porque é um parametro de entrada
{

	int but1L = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	int but2L = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
	int but3L = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	int but4L = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);




	if(but1L == 0){
		return '1';
	}

	if(but2L == 0){
		return '2';
	}

	if(but3L == 0){
		return '3';
	}

	if(but4L == 0){
		return '4';
	}

	return 0;
}




char LeBotaoColuna(void){
	int but1C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
	int but2C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
	int but3C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
	int but4C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);


	if(but1C == 0){
		return 'A';
	}

	if(but2C == 0){
		return 'B';
	}

	if(but3C == 0){
		return 'C';
	}

	if(but4C == 0){
		return 'D';
	}

	return 0;
}









void ligabuzz(){

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);


}









void desligabuzz(){

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);


}











void TestaTeclado(char *Pu){


	char x, y;




x = LeBotaoColuna();

	if(x != 0 ){
		*Pu = x;
		Pu++;
		}






y = LeBotaoLinha();

	if(y != 0){
		*Pu = y;
		Pu++;


		}

	verifica();





}


void apertaTB(){

	int but1L = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
		int but2L = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
		int but3L = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
		int but4L = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		int but1C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
			int but2C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
			int but3C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
			int but4C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);

			if(but1L == 0 && but2L == 0 && but3L == 0 && but4L == 0 ){
				iniciaJogo();

			}else if(but1C == 0 && but2C == 0 && but3C == 0 && but4C == 0){
				iniciaJogo();
			}



}
void iniciaJogo(){

AleatorizaPosicao();
TestaTeclado(&v[0]);


}

void verifica(){

	//TestaTeclado(&v[0]);

	if (v[0]  == 'A' || v[0]  == 'B' ||v[0]  == 'C' || v[0]  =='D' && v[1]  == '1' || v[1] == '2' || v[1] == '3' || v[1] == '4'){// funçao de verificar bomba
		int colunaM = v[0] - 'A';
		int LinhaM = v[1] - '0';
		int LinhaF = LinhaM - 1;

			if(matriz[LinhaF][colunaM] == 1 ){
					FimDeJogo();
					apertaTB();
			}


	else{

		JogadaCerta();
		 TestaTeclado(&v[0]);
		}
}
	else{

		v[0]="X";
		v[1]= "x";
		apertaTB();

	}
}








void FimDeJogo(void){



		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 1);//1


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);//2


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);//3


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);//4


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);//5


		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);//6


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);//7


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);//8


					HAL_Delay(200);


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);//1


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);//2


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);//3


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//4


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);//5


		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);//6


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);//7


		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);//8




//BUZZER
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);//Buzzer

					HAL_Delay(3000);

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);//Buzzer




	// while(but1 == 0 || but2 == 0 || but3 == 0 || but4 == 0){

//}
}
void JogadaCerta(){


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 1);//1


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);//2


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);//3


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);//4


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);//5


			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);//6


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);//7


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);//8


						HAL_Delay(1000);


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);//1


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);//2


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);//3


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//4


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);//5


			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);//6


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);//7


			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);//8


						HAL_Delay(1000);



}





void AleatorizaPosicao() {
    int linha, coluna;


    for (int i = 0; i <= 4; i++) {
    		linha = rand() % 4;
    		coluna = rand() % 4;

        // Verifica se a posição já possui o valor 1
    	while (matriz[linha][coluna] == 1) {
            linha = rand() % 4;
            coluna = rand() % 4;
            break;

        }
        matriz[linha][coluna] = 1;
    }




}

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
