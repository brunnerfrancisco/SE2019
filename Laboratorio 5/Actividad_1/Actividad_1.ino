#include <Arduino_FreeRTOS.h>
#include "semphr.h"
#define INCLUDE_vTaskSuspend                    1

SemaphoreHandle_t xMutexPrender;
SemaphoreHandle_t xMutexApagar;

void prender(void *parameters);
void apagar(void *parameters);

void setup() {
  
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
  xMutexApagar = xSemaphoreCreateMutex();
  xMutexPrender = xSemaphoreCreateMutex();
  
  xSemaphoreGive(xMutexPrender);
  
  xTaskCreate(apagar,  "apagar", 128, NULL, 2, NULL);    
  xTaskCreate(prender, "prender", 128, NULL, 2, NULL); 
                  
}

void loop() 
{
}

void prender( void * parameter )
{
    for(;;)
    {
        if (xSemaphoreTake( xMutexApagar,999)== pdTRUE)
        {
            digitalWrite(8,HIGH);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            xSemaphoreGive( xMutexPrender );
        }
    }
}

void apagar( void * parameter )
{
    for(;;)
    {
        if (xSemaphoreTake( xMutexPrender,999)== pdTRUE)
        {
        digitalWrite(8,LOW);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        xSemaphoreGive( xMutexApagar );
        }
    
    }
}
