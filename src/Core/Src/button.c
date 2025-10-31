#include "button.h"

// Variables 
static SPI_HandleTypeDef* hspi_button = NULL; // SPI handle for button module

static int16_t spi_receive_buffer = 0xFFFF;

static Button current_buttons_state;

// Private Functions Definition

// Global Functions Defintion
int8_t button_init(SPI_HandleTypeDef* hspi){
    if(hspi == NULL){
        return -1;
    }

    current_buttons_state.buttons_state = 0xFFFF;

    hspi_button = hspi;
}

Button get_buttons_state(void){
    return current_buttons_state;
}

void update_buttons_state(void){
    HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, GPIO_PIN_SET);
    HAL_SPI_Receive(hspi_button, (void*)spi_receive_buffer, SPI_RECEIVE_BUFFER_SIZE, HAL_MAX_DELAY);

    current_buttons_state.buttons_state = spi_receive_buffer;

}
