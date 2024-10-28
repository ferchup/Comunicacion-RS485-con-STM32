/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <string.h>

#include "checksum.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define BUFFER_SIZE 256

extern uint8_t NewMessage;

extern uint16_t ns;

extern uint8_t RxByte;
extern uint16_t RxLen;

extern uint8_t RxData[BUFFER_SIZE];
extern uint8_t TxData[BUFFER_SIZE];
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void USART_transmit_data(UART_HandleTypeDef* huart, uint8_t* message, uint16_t size);
void USART_receive_data(UART_HandleTypeDef* huart, uint8_t* message, uint32_t size);

void RS485_transmit_data(uint8_t* packet, uint16_t packet_size);
void RS485_create_packet(uint8_t* packet, uint16_t* packet_size, uint8_t* message, uint8_t ack, uint8_t id);
uint8_t RS485_decode_packet(uint8_t* packet, uint16_t* packet_size, uint8_t* message, uint8_t* message_size, uint16_t* ns_aux, uint8_t* ack, uint8_t* id);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

