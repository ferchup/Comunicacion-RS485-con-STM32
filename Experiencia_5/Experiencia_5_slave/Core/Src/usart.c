/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
//Flag de nuevo mensaje entrante
uint8_t NewMessage = 0;

//Variables para crear mensaje por interrupción
uint8_t RxByte = 0;
uint16_t RxLen = 0;

//Variables para la trama
uint16_t ns = 0;

uint8_t RxData[BUFFER_SIZE] = {0};
uint8_t TxData[BUFFER_SIZE] = {0};
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PC4     ------> USART1_TX
    PC5     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PC4     ------> USART1_TX
    PC5     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_4|GPIO_PIN_5);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin|STLK_TX_Pin);

  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void USART_transmit_data(UART_HandleTypeDef* huart, uint8_t* message, uint16_t size)
{
	HAL_UART_Transmit(huart, (uint8_t *) message, size, 1000);
}

void USART_receive_data(UART_HandleTypeDef* huart, uint8_t* message, uint32_t size)
{
	HAL_UART_Receive(huart, message, size, 100000);
}

void RS485_transmit_data(uint8_t* packet, uint16_t packet_size)
{
	HAL_GPIO_WritePin(RS485_E_GPIO_Port, RS485_E_Pin, GPIO_PIN_SET);
	USART_transmit_data(&huart1, packet, packet_size);
	HAL_GPIO_WritePin(RS485_E_GPIO_Port, RS485_E_Pin, GPIO_PIN_RESET);
}

/**
 * @brief Create a packet from a message given with this struct.
 * .----------------------------------------------.
 * | NS | SIZE_DATA | ACK | ID | DATA | CRC | END |
 * |----------------------------------------------|
 * | 2B |     1B    | 1B  | 1B | 248< | 2B  | 1B  |
 * .----------------------------------------------.
 * @param packet Packet to decode.
 * @param packet_size Full packet size.
 * @param message Message inside the packet.
 * @param ack 1 if is ACK packet 0 if not.
 * @param id Identifier of the packet sender.
*/
void RS485_create_packet(uint8_t* packet, uint16_t* packet_size, uint8_t* message, uint8_t ack, uint8_t id)
{
	uint16_t crc;
    uint8_t message_size = strlen((char *)message); // Tamaño del mensaje

    // Copiamos el número de trama (NS) - 2 bytes
    memcpy(packet, &ns, 2);
    // Copiamos el tamaño del mensaje (SIZE_DATA) - 1 bytes (MAX 250 bytes de mensaje)
    memcpy(&packet[2], &message_size, 1);
    //Ack
    memcpy(&packet[3], &ack, 1);
    //Ack
    memcpy(&packet[4], &id, 1);
    // Copiamos el mensaje (DATA) - tamaño variable (hasta 249 bytes)
    memcpy(&packet[5], message, message_size);

    // Calculamos el CRC (usando una función crc_16 adecuada) - 2 bytes
    crc = crc_16((unsigned char *)packet, message_size + 5); // Calculamos CRC sobre NS + SIZE_DATA + DATA
    memcpy(&packet[5 + message_size], &crc, 2);

    // Añadimos el byte de fin de trama (END) - 1 byte
    packet[5 + message_size + 2] = 0x0A;  // Byte de fin de trama
    packet[5 + message_size + 3] = 0; // Añadimos el final de cadena

    //Devolvemos el tamaño del paquete total
    *packet_size = message_size + 8;
}


/**
  * @brief Decode a packet given.
  * @param packet Packet to decode.
  * @param packet_size Full packet size.
  * @param message Message inside the packet.
  * @param message_size Message inside the packet size.
  * @param ns_aux Number of sequence of the packet given.
  * @param ack 1 if is ACK packet 0 if not.
  * @param id Identifier of the packet sender.
  */
uint8_t RS485_decode_packet(uint8_t* packet, uint16_t* packet_size, uint8_t* message, uint8_t* message_size, uint16_t* ns_aux, uint8_t* ack, uint8_t* id)
{
	uint16_t crc_rx = 0, crc_calc = 0;

	memcpy(ns_aux, packet, 2);
	memcpy(message_size, &packet[2], 1);
	memcpy(ack, &packet[3], 1);
	memcpy(id, &packet[4], 1);
	memcpy(message, &packet[5], *message_size);

	memcpy(&crc_rx, &packet[5 + *message_size], 2);
	crc_calc = crc_16((unsigned char *)packet, *message_size + 5);

	*packet_size = *message_size + 8;

	return crc_rx == crc_calc;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(RxByte != 0x0A || RxLen < 9)
	{
		RxData[RxLen] = RxByte;
		RxLen++;
	}else
	{
		RxLen = 0;
		NewMessage = 1;
	}

	if(HAL_UART_Receive_IT(&huart1, &RxByte, 1) != HAL_OK)
	{
		Error_Handler();
	}
}
/* USER CODE END 1 */
