/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);
	
	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
	  ringBuffer->buffer = dataBuffer;
	  ringBuffer->capacity = dataBufferSize;
	  ringBuffer->len = 0;
	  ringBuffer->head = 0;
	  ringBuffer->tail = 0;
	  return true;
	}
	
	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		ringBuffer->head = 0;
		ringBuffer->tail = 0;
		ringBuffer->len = 0;
		return true;
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);	
	if (ringBuffer) {
		return (ringBuffer->len == 0);
	}
	
	return true;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->len;
	}
	return 0;
	
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->capacity;
	}
	return 0;	
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		if(ringBuffer->len >= ringBuffer->capacity) {
			return false; // Buffer is full
		}
		ringBuffer->buffer[ringBuffer->head] = c;
		ringBuffer->head = (ringBuffer->head + 1) % ringBuffer->capacity;
		ringBuffer->len++;
		return true;
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);
	
  if ((ringBuffer) && (c)) {
		if (ringBuffer->len == 0) {
			return false; // Buffer is empty
		}
		*c = ringBuffer->buffer[ringBuffer->tail];
		ringBuffer->tail = (ringBuffer->tail + 1) % ringBuffer->capacity;
		ringBuffer->len--;
		return true;
	}
	return false;
}
