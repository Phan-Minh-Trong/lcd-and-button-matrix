#include "lcd.h"

// Variables


// Private Functions Definition


// Global Functions Defintion
int8_t lcd_init(void){
    HAL_Delay(500);
    HAL_GPIO_WritePin(FSMC_RES_GPIO_Port, FSMC_RES_Pin, GPIO_PIN_RESET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(FSMC_RES_GPIO_Port, FSMC_RES_Pin, GPIO_PIN_SET);
}








