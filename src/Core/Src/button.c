#include "button.h"

// Variables 
static SPI_HandleTypeDef* hspi_button = NULL; // SPI handle for button module

static int8_t spi_receive_buffer[SPI_RECEIVE_BUFFER_SIZE] = {
    0x00,
    0x00
};

static Button buttons;

// Private Functions Definition
// TODO: Implement debounce function

// Global Functions Defintion
int8_t button_init(SPI_HandleTypeDef* hspi){
    if(hspi == NULL){
        return -1;
    }

    for(int i = 0; i<TOTAL_BUTTONS; ++i){
        buttons.buttons_state[i] = BUTTON_RELEASED;
    }

    hspi_button = hspi;
}

Button get_buttons_state(void){
    return buttons;
}

void update_buttons_state(void){
    HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, GPIO_PIN_RESET);
    HAL_SPI_Receive(hspi_button, (uint8_t*)spi_receive_buffer, SPI_RECEIVE_BUFFER_SIZE, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, GPIO_PIN_SET);

    // Debounce process....

    // Update states....
}
