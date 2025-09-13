#include QMK_KEYBOARD_H

#define QWERTY 0
#define NAVIGATE 1
#define SYMBOLS 2
#define NUMPAD 3
#define ADJUST 4







// =================== Defines auxiliares ===================
#define GUI_ENT  GUI_T(KC_ENT)
#define ALT_SHIFT MT(MOD_LALT | MOD_LSFT, KC_NO)   // Alt + Shift
#define CTRL_SHIFT MT(MOD_LCTL | MOD_LSFT, KC_NO)  // Ctrl + Shift
#define CMD_C LGUI(KC_C)                           // Command + C
#define CMD_V LGUI(KC_V)                           // Command + V
#define CTRL_SPC MT(MOD_LCTL, KC_SPC)
#define WIN_ALT_HOLD MT(MOD_LGUI | MOD_LALT, KC_NO)
#define ESC_WIN MT(MOD_LGUI, KC_ESC)
// =================== Keymaps ===================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_BSPC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    LSFT_T(KC_SLSH),

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LALT), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    LALT_T(KC_MINS),

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    ESC_WIN,

  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     KC_LGUI, LT(3, GUI_ENT), MO(1), MO(2), CTRL_SPC, KC_LCTL
                                      //`--------------------------'  `--------------------------'
  ),










  [1] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  XXXXXXX, XXXXXXX, KC_UP,  XXXXXXX  ,   XXXXXXX,                      XXXXXXX,KC_PGUP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, KC_LEFT,KC_DOWN, KC_RIGHT, XXXXXXX,                      WIN_ALT_HOLD,KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CTRL_SHIFT,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS, KC_TRNS,    MO(4),KC_TRNS ,KC_TRNS \
                                      //`--------------------------'  `--------------------------'
    ),


  [2] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_AT,   KC_EXLM, KC_LPRN, KC_RPRN, KC_PERC,                        KC_EQL,  KC_PPLS, KC_PAST,   KC_NO,   KC_NO,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LSFT, KC_LALT, KC_LCBR, KC_RCBR, KC_MINS,                      KC_EXLM, KC_HASH, KC_SLSH, KC_BSLS, KC_PIPE,KC_DLR,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, S(KC_MINS),                   KC_COLON, KC_GRV,  KC_CIRC, KC_AT, KC_AMPR, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, MO(4),     KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     KC_PPLS, KC_1, KC_2, KC_3, KC_MINS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LSFT, KC_LALT, KC_MPRV,XXXXXXX,XXXXXXX,                    KC_PAST, KC_4, KC_5, KC_6, KC_SLSH, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,                     KC_0,    KC_7, KC_8, KC_9, KC_PERC, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, _______,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),




[4] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_F1, KC_F2, KC_F3,KC_F4, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                     XXXXXXX, KC_F5, KC_F6, KC_F7,KC_F8, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                     XXXXXXX, KC_F9, KC_F10, KC_F11,KC_F12, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, _______,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  )





};

#ifdef OLED_ENABLE

    char keylog_str[24] = {};

    void oled_render_layer_state(void) {
        oled_write_P(PSTR("Layer: "), false);
        switch (layer_state) {
            case QWERTY :
                oled_write("QWERTY", false);
                break;
            case NAVIGATE :
                oled_write("NAVIGATE", false);
                break;
            case SYMBOLS :
                oled_write("SYMBOLS", false);
                break;
            case NUMPAD :
                oled_write("NUMPAD", false);
                break;
            case ADJUST :
                oled_write("ADJUST", false);
                break;
        }
    }

    void oled_render_logo(void) {
        static const char PROGMEM crkbd_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
            0};
        oled_write_P(crkbd_logo, false);
    }

    void oled_render_keylog(void) {
        oled_write(keylog_str, false);
    }

    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
            oled_render_keylog();
        } else {
            oled_render_logo();
        }
        return false;
    }
#endif
