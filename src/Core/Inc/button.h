#ifndef __BUTTON_H__
#define __BUTTON_H__

// Essential libraries
#include "stdint.h"
#include "main.h"

// Macros
#define BUTTON_PRESSED  1 // Button is pressed
#define BUTTON_RELEASED 0 // Button is released
#define TOTAL_BUTTONS 16  // Total buttons count
#define SPI_RECEIVE_BUFFER_SIZE 2 // Total bytes receive from IC 74HC165

#define BUTTON_0     0
#define BUTTON_1     1
#define BUTTON_2     2
#define BUTTON_3     3
#define BUTTON_4     4
#define BUTTON_5     5
#define BUTTON_6     6
#define BUTTON_7     7
#define BUTTON_8     8
#define BUTTON_9     9
#define BUTTON_10   10
#define BUTTON_11   11
#define BUTTON_12   12
#define BUTTON_13   13
#define BUTTON_14   14
#define BUTTON_15   15

typedef struct Button{
    uint8_t buttons_state[TOTAL_BUTTONS];
} Button;

/**
 * @brief
 * Initialize button module (must be call before using).
 * @param hspi: Pointer to SPI handle
 * @return 0 on success, -1 on errors
 */
int8_t button_init(SPI_HandleTypeDef* hspi);

/**
 * @brief
 * Get all the buttons state (BUTTON_PRESSED or BUTTON_RELEASED)
 * @param None
 * @return All button states
 */
Button get_buttons_state(void);

/**
 * @brief
 * This function updates all buttons state, the main core of the button module relies on this function (this function should be called in an interrupt function).
 * @param None
 * @return None
 */
void update_buttons_state(void);


#endif // __BUTTON_H__