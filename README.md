# lcd-and-button-matrix
## Overview
A simple LCD module and Button module project from the Embedded Systems lab (CO3053), HCMUT.

This project is written for STM32F407ZGT6.

## Button Module
### Basic structure
The STM32F407ZGT6 will use 2 IC 74HC165 to communicate with the Button Module.

This is the button map on ARM4 kit
```
    1  2  3  ^    ~    BTN1   BTN2   BTN3   BTN4
    4  5  6  v    ~    BTN8   BTN7   BTN6   BTN5
    7  8  9  >    ~    BTN9   BTN10  BTN11  BTN12
    E  0  B  <    ~    BTN16  BTN15  BTN14  BTN13
The SPI will receive the packet in reference to the Button map above:
{1, 2, 3, ^, v, 6, 5, 4, 7, 8, 9, >, <, B, 0, E}
 ^                                            ^
 |                                            |
MSB                                          LSB
```

### Using Button Module
`Button` type:
```
typedef struct Button{
    uint16_t buttons_state;
} Button;
```

The Button module exposes the following functions. Signatures are in `button.h`.

+ `int8_t button_init(SPI_HandleTypeDef* hspi);`
    - Init Button module, should be called once after init SPI
    - Returns 0 on success, -1 on fail

+ `Button get_buttons_state(void);`
    - Get the current button state (BUTTON_PRESSED or BUTTON_RELEASED)
    - Return the `Button` type

+ `void update_buttons_state(void);`
    - Scan all 16 buttons in the module and update its state.
    - This function should be polled when interrupt occurs (should interrupt every 50ms)

Usage example:

This example check for BTN7 state (BUTTON_PRESSED or BUTTON_RELEASE)
```
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance == TIM2){
        update_buttons_state();
    }
}

uint8_t check_BTN7(){
    uint16_t mask = 0x0080;
    Button button = get_buttons_state();
    return mask & button.buttons_state;
}
```


