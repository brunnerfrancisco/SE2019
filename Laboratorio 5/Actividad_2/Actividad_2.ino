#include <Arduino_FreeRTOS.h>
#include "semphr.h"
#define INCLUDE_vTaskSuspend                    1

SemaphoreHandle_t xContVacio;
SemaphoreHandle_t xContLleno;
SemaphoreHandle_t xMutexEscribo;

void consumidor(void *parameters);
void productorA(void *parameters);
void productorB(void *parameters);

uint32_t vector[5];
uint8_t size;

void setup() {
  
  Serial.begin(9600);

  size = 0;
  
  xContVacio = xSemaphoreCreateCounting( 5, 5 );
  xContLleno = xSemaphoreCreateCounting( 5, 0 );
  xMutexEscribo = xSemaphoreCreateMutex();
  
  xSemaphoreGive(xMutexEscribo);
  
  xTaskCreate(productorA,  "apagar", 128, NULL, 1, NULL);
  xTaskCreate(productorB,  "apagar", 128, NULL, 1, NULL);    
  xTaskCreate(consumidor, "prender", 128, NULL, 2, NULL); 
                  
}

void loop() 
{
}

void productorA( void * parameter )
{
    for(;;)
    {
        xSemaphoreTake( xContVacio,999);
        xSemaphoreTake( xMutexEscribo,999);
        Serial.println("Escribio 1");
        vector[size] = 1;
        size++;    
        xSemaphoreGive( xMutexEscribo );
        xSemaphoreGive(xContLleno);
        vTaskDelay(50/portTICK_PERIOD_MS);
    }
}


void productorB( void * parameter )
{
    for(;;)
    {
        xSemaphoreTake( xContVacio,999);
        xSemaphoreTake(xMutexEscribo,999);
        Serial.println("Escribio 2");
        vector[size] = 2;
        size++;    
        xSemaphoreGive( xMutexEscribo );
        xSemaphoreGive(xContLleno);
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}

void consumidor( void * parameter )
{
    for(;;)
    {
        xSemaphoreTake( xContLleno,1000);
        xSemaphoreTake(xMutexEscribo,1000);
        Serial.print("Consumi: ");
        Serial.println(vector[size-1]);
        size--;    
        xSemaphoreGive( xMutexEscribo );
        xSemaphoreGive(xContVacio);
        vTaskDelay(75/portTICK_PERIOD_MS);
    }
}
