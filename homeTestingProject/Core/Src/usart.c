/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include "ring_buffer.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_bus.h"

// UART transmit buffer descriptor
static RingBuffer USART_RingBuffer_Tx;
// UART transmit buffer memory pool
static char RingBufferData_Tx[1024];

// UART receive buffer descriptor
static RingBuffer USART_RingBuffer_Rx;
// UART receive buffer memory pool
static char RingBufferData_Rx[1024];


bool USART_PutChar(char c){
	if(RingBuffer_PutChar(&USART_RingBuffer_Tx, c)) {
		LL_USART_EnableIT_TXE(USART2);
		return true;
	}

	return false;
}


size_t USART_WriteData(const void *data, size_t dataSize){
	const char* bytes = (const char*)data;
	size_t counter;
	for(counter = 0; counter < dataSize; counter++) {
		char c = bytes[counter];
		if(!USART_PutChar(c)) {
			return counter;
		}
	}
	return counter;
}


size_t USART_WriteString(const char *string){

	size_t len = strlen(string);
	return USART_WriteData((const void*)string, len);
}


bool USART_GetChar(char *c){
	return RingBuffer_GetChar(&USART_RingBuffer_Rx, c);
}


size_t USART_ReadData(void *data, size_t maxSize){
	char *bytes = (char*)data;
	size_t counter = 0;
	while(counter < maxSize && USART_GetChar(&bytes[counter])) {
		counter++;
	}
	return counter;
}


// USART1 Interrupt Service Routine (ISR)
void USART2_IRQHandler(void){
	if (LL_USART_IsActiveFlag_TXE(USART2)) {
		// The TXE interrupt has occurred
		// TODO: get a character from the transmit ring buffer and send it via UART
		//       if no characters are left to send - disable the TXT interrupt source
		char c;
		if(RingBuffer_GetChar(&USART_RingBuffer_Tx, &c)) {
			LL_USART_TransmitData8(USART2, c);
		} else {
			LL_USART_DisableIT_TXE(USART2);
		}
	}
	if (LL_USART_IsActiveFlag_RXNE(USART2)) {
		// the RXNE interrupt has occurred
		// TODO: read the received character and place it in the receive ring buffer
		char c = LL_USART_ReceiveData8(USART2);
		RingBuffer_PutChar(&USART_RingBuffer_Rx, c);
	}
}


/**
 * This function initialize ring buffers, USART device and enable receive interrupt.
 */
void USART_Init(void){
	// initialize ring buffers
	RingBuffer_Init(&USART_RingBuffer_Tx, RingBufferData_Tx, sizeof(RingBufferData_Tx));
	RingBuffer_Init(&USART_RingBuffer_Rx, RingBufferData_Rx, sizeof(RingBufferData_Rx));

	// Peripheral clock enable
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

	// GPIO configuration
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// USART1 interrupt init
	NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(USART2_IRQn);

	// USART1 peripheral init
	LL_USART_InitTypeDef USART_InitStruct = {0};
	USART_InitStruct.BaudRate = 115200;
	USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
	USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
	USART_InitStruct.Parity = LL_USART_PARITY_NONE;
	USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
	USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
	LL_USART_Init(USART2, &USART_InitStruct);
	LL_USART_ConfigAsyncMode(USART2);
	LL_USART_Enable(USART2);
	LL_USART_EnableIT_RXNE(USART2);
}


