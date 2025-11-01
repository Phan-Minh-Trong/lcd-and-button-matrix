#ifndef __LCD_H__
#define __LCD_H__

// Essential libraries
#include "stdint.h"
#include "main.h"

// Macros
//// Regulative Command Set
#define LCD_NO_OPERATION    0x0000          // No operation
#define LCD_SOFTWARE_RESET  0x0001          // Software Reset
#define LCD_R_DISPLAY_ID    0x0004          // Read Display Identification Information
#define LCD_R_DISPLAY_STAT  0x0009          // Read Display Status
#define LCD_R_DISPLAY_POW_MODE  0x000A      // Read Display Power Mode
#define LCD_R_DISPLAY_MADCTL    0x000B      // Read Display MADCTL
#define LCD_R_DISPLAY_PIX_FORM  0x000C      // Read Display Pixel Format
#define LCD_R_DISPLAY_IMG_FORM  0x000D      // Read Display Image Format
#define LCD_R_DISPLAY_SIG_MODE  0x000E      // Read Display Signal Mode
#define LCD_R_DISPLAY_DIAG_RES  0X000F      // Read Display Self-Diagnostic Result
#define LCD_ENTER_SLP_MODE  0x0010          // Enter Sleep Mode
#define LCD_SLP_OUT         0x0011          // Sleep OUT
#define LCD_PARTIAL_MODE_ON 0x0012          // Partial Mode ON
#define LCD_NORM_DISPLAY_ON 0x0013          // Normal Display Mode ON
#define LCD_DISPLAY_INVERSE_OFF 0x0020      // Display Inversion OFF
#define LCD_DISPLAY_INVERSE_ON  0x0021      // Display Inversion ON
#define LCD_GAMMA_SET   0x0026              // Gamma Set
#define LCD_DISPLAY_OFF 0x0028              // Display OFF
#define LCD_DISPLAY_ON  0x0029              // Display ON
#define LCD_COL_ADDR_SET    0x002A          // Column Address Set
#define LCD_PAGE_ADDR_SET   0x002B          // Page Address Set
#define LCD_MEM_WRITE   0x002C              // Memory Write
#define LCD_COLOR_SET   0x002D              // Color SET
#define LCD_MEM_READ    0x002E              // Memory Read
#define LCD_PARTIAL_AREA    0x0030          // Partial Area 
#define LCD_VERT_SCROL_DEF  0x0033          // Vertical Scrolling Definition
#define LCD_TEARING_EFF_OFF 0x0034          // Tearing Effect Line OFF
#define LCD_TEARING_EFF_ON  0x0035          // Tearing Effect Line ON
#define LCD_MEM_ACCESS_CTRL 0x0036          // Memory Access Control
#define LCD_VER_SCROL_START_ADDR    0x0037  // Vertical Scrolling Start Address
#define LCD_IDLE_MODE_OFF   0x0038          // Idle Mode OFF
#define LCD_IDLE_MODE_ON    0x0039          // Idle Mode ON
#define LCD_PIX_FORM_SET    0x003A          // Pixel Format Set
#define LCD_W_MEM_CONT  0x003C              // Write Memory Continue
#define LCD_R_MEM_CONT  0x003E              // Read Memory Continue
#define LCD_SET_TEAR_SCANL  0x0044          // Set Tear Scanline
#define LCD_GET_SCANL   0x0045              // Get Scanline
#define LCD_W_DISPLAY_BRIGHT    0x0051      // Write Display Brightness
#define LCD_R_DISPLAY_BRIGHT    0x0052      // Read Display Brightness
#define LCD_W_CTRL_DISPLAY  0x0053          // Write CTRL Display
#define LCD_R_CTRL_DISPLAY  0x0054          // Read CTRL Display 
#define LCD_W_CABC  0x0055                  // Write Content Adaptive Brightness Control
#define LCD_R_CABC  0x0056                  // Read Content Adaptive Brightness Control
#define LCD_W_CABC_MIN_BRIGHT   0x005E      // Write CABC Minimum Brightness
#define LCD_R_CABC_MIN_BRIGHT   0x005F      // Read CABC Minimum Brightness
#define LCD_R_ID1   0x00DA                  // Read ID1
#define LCD_R_ID2   0x00DB                  // Read ID2
#define LCD_R_ID3   0x00DC                  // Read ID3

//// Extended Command Set
#define LCD_RGB_INTERFACE_SIG_CTRL  0x00B0  // RGB Interface Signal Control
#define LCD_FRAME_CTRL_NORM 0x00B1          // Frame Control (In Normal Mode)
#define LCD_FRAME_CTRL_IDLE 0x00B2          // Frame Control (In Idle Mode)
#define LCD_FRAME_CTRL_PART 0x00B3          // Frame Control (In Partial Mode)
#define LCD_DISP_VER_CTRL   0x00B4          // Display Inversion Control
#define LCD_BLANK_PORCH_CTRL    0x00B5      // Blanking Porch Control
#define LCD_DISP_FUNC_CTRL  0x00B6          // Display Function Control
#define LCD_ENTRY_MODE_SET  0x00B7          // Entry Mode Set
#define LCD_BACKLIGHT_CTRL1 0x00B8          // Backlight Control 1
#define LCD_BACKLIGHT_CTRL2 0x00B9          // Backlight Control 2 
#define LCD_BACKLIGHT_CTRL3 0x00BA          // Backlight Control 3 
#define LCD_BACKLIGHT_CTRL4 0x00BB          // Backlight Control 4 
#define LCD_BACKLIGHT_CTRL5 0x00BC          // Backlight Control 5
#define LCD_BACKLIGHT_CTRL7 0x00BE          // Backlight Control 7
#define LCD_BACKLIGHT_CTRL8 0x00BF          // Backlight Control 8
#define LCD_POW_CTRL1   0x00C0              // Power Control 1 
#define LCD_POW_CTRL2   0x00C1              // Power Control 2 
#define LCD_VCOM_CTRL1  0x00C5              // VCOM Control 1
#define LCD_VCOM_CTRL2  0x00C7              // VCOM Control 2
#define LCD_NV_MEM_W    0x00D0              // NV Memory Write
#define LCD_NV_MEM_PROC_K   0x00D1          // NV Memory Protection Key
#define LCD_NV_MEM_STAT_R   0x00D2          // NV Memory Status Read
#define LCD_R_ID4   0x00D3                  // Read ID4
#define LCD_POS_GAMM_CORRECTION 0x00E0      // Positive Gamma Correction
#define LCD_NEG_GAMM_CORRECTION 0x00E1      // Negative Gamma Correction
#define LCD_DIGI_GAMM_CTRL1 0x00E2          // Digital Gamma Control 1
#define LCD_DIGI_GAMM_CTRL2 0x00E3          // Digital Gamma Control 2
#define LCD_INTERFACE_CTRL  0x00F6          // Interface Control

/**
 * @brief
 * Initialize lcd module (must be call before using).
 * @param hspi: Pointer to SPI handle
 * @return 0 on success, -1 on errors
 */
int8_t lcd_init(void);








#endif // __BUTTON_H__