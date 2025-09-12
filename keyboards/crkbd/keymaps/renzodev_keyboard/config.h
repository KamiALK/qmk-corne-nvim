#pragma once

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100
#define MASTER_RIGHT
#define SPLIT_USB_DETECT
#define RGBLIGHT_SLEEP

#ifdef RGBLIGHT_ENABLE
    // #define RGB_DI_PIN D3          // ⚠️ depende de tu PCB (a veces D3, D4 o F4 en Corne)
    #define RGBLED_NUM 54          // número total de LEDs (27 por lado en Corne con full RGB)
    #define RGB_MATRIX_SPLIT {27, 27}
    #define RGB_MATRIX_KEYPRESSES
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE

#endif
