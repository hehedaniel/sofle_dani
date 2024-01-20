  #pragma once


//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


#define MASTER_LEFT


// #define MASTER_RIGHT
// #define EE_HANDS

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


// home row mods 

// #define TAPPING_TERM 300


#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

// #define MOUSEKEY_INTERVAL 40
#define MOUSEKEY_WHEEL_DELTA 1

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 35    // Number of LEDs
#define RGBLED_NUM 35    // Number of LEDs
#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

	#define RGBLIGHT_EFFECT_BREATHING
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	#define RGBLIGHT_EFFECT_RGB_TEST
	#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 70
	#define RGBLED_SPLIT { 35, 35 } // haven't figured out how to use this yet

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
