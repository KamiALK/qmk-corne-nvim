#include QMK_KEYBOARD_H

#define QWERTY 0
#define NAVIGATE 1
#define SYMBOLS 2
#define NUMPAD 3
#define ADJUST 4
#define MULTIMEDIA 5

// =================== Defines auxiliares ===================
#define GUI_ENT  GUI_T(KC_ENT)
#define ALT_SHIFT MT(MOD_LALT | MOD_LSFT, KC_NO)   // Alt + Shift
#define CTRL_SHIFT MT(MOD_LCTL | MOD_LSFT, KC_NO)  // Ctrl + Shift
#define CMD_C LGUI(KC_C)                           // Command + C
#define CMD_V LGUI(KC_V)                           // Command + V
#define CTRL_SPC MT(MOD_LCTL, KC_SPC)
#define WIN_ALT_HOLD MT(MOD_LGUI | MOD_LSFT, KC_NO)
#define ESC_WIN MT(MOD_LGUI, KC_ESC)

// =================== Custom keycodes ===================
enum custom_keycodes {
    VIM_GCC = SAFE_RANGE,    // ESC + g + c + c
    VIM_XX,                  // ESC + SPACE + x + x
    VIM_NVIM,                // n + v + i + m + SPACE + . + ENTER
    VIM_50YJ,                // ESC + 5 + 0 + y + j
    VIM_50YK,                // ESC + 5 + 0 + y + k
    VIM_AT_C,                // ESC + SHIFT + @ + c
    TABU,
};

// =================== Tap Dance ===================
enum {
    TD_VIM_GCC = 0,
    TD_DIAG_W,     // warnings
    TD_DIAG_D,     // diagnósticos
    TD_DIAG_E,     // errors
    TD_DIAG_T,     // trouble/todo
    TD_VIM_XX,     // ✅ AGREGA ESTA LÍNEA
    TD_WIN_TAB_L5, // WIN+TAB tap, Layer 5 hold
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_BSPC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  TD(TD_WIN_TAB_L5)  ,

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
ESC_WIN , KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    LALT_T(KC_MINS),

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    LSFT_T(KC_SLSH),

  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     TD(TD_VIM_GCC),  MO(1),CTRL_SPC,  LT(3, GUI_ENT),MO(2),TD(TD_VIM_XX)
                                      // `--------------------------'  `-
        // :-------------------------'
  ),

  [1] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,LGUI(KC_Q), XXXXXXX, KC_UP,  XXXXXXX,   KC_TAB,                    KC_T,KC_PGUP,VIM_50YK,VIM_AT_C,VIM_NVIM, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, KC_LEFT,KC_DOWN, KC_RIGHT,KC_LCTL,                      WIN_ALT_HOLD,KC_PGDN,KC_T, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, CTRL_SHIFT,                  KC_LALT,CTRL_SHIFT,TABU, XXXXXXX,  XXXXXXX, _______,\
  // |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS, KC_TRNS,    KC_TRNS, MO(4),KC_TRNS \
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
                                          KC_LGUI, MO(4),KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_MPRV, XXXXXXX,LALT(KC_W) ,KC_LBRC,KC_RBRC,                     KC_PPLS, KC_1, KC_2, KC_3, KC_MINS,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, CTRL_SHIFT,LALT(KC_A),LALT(KC_S),LALT(KC_D),XXXXXXX,                    KC_PAST, KC_4, KC_5, KC_6, KC_SLSH, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LALT, TD(TD_DIAG_W), TD(TD_DIAG_D), TD(TD_DIAG_E), TD(TD_DIAG_T), KC_0,    KC_7, KC_8, KC_9, KC_PERC, KC_LGUI,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, _______,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      // `--------------------------'  `--------------------------'
  ),

[4] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_F1, KC_F2, KC_F3,KC_F4, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                     XXXXXXX, KC_F5, KC_F6, KC_F7,KC_F8, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                     XXXXXXX, KC_F9, KC_F10, KC_F11,KC_F12, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, _______,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),
[5] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, LGUI(KC_1), LGUI(KC_2),LGUI(KC_3),LGUI(KC_4), LGUI(KC_5),        LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX, XXXXXXX,\

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_Q,                      KC_PGUP, XXXXXXX, LGUI(KC_T), XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,LGUI(KC_Q), KC_VOLD, KC_MUTE, KC_VOLU, CTRL_SHIFT,                KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_LCTL,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  )
};


// =================== Process Record User ===================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case VIM_NVIM:
            if (record->event.pressed) {
                SEND_STRING("nvim ." SS_TAP(X_ENT));
            }
            break;
        case VIM_50YJ:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) "50yj");
            }
            break;
        case VIM_50YK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) "50yk");
            }
            break;
        case VIM_AT_C:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT("2") "c");  // SHIFT+2 = @
            }
            break;
        case TABU:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SPC) "`");  // Espacio usando SS_TAP + backtick
            }
            break;
    }
    return true;
}

// =================== Tap Dance Functions ===================
// Función de tap dance para VIM_GCC
void vim_gcc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            // Hold: activar Alt
            register_code(KC_LALT);
        } else {
            // Tap: ejecutar macro vim gcc
            SEND_STRING(SS_TAP(X_ESC) "gcc");
        }
    }
}


void vim_gcc_reset(tap_dance_state_t *state, void *user_data) {
    // Liberar Alt SIEMPRE al resetear
    unregister_code(KC_LALT);
}
// ✅ AGREGA ESTA FUNCIÓN:
void vim_xx_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // 1 tap: ESC + espacio + xx
        SEND_STRING(SS_TAP(X_ESC) " xx");
    } else if (state->count == 2) {
        // 2 taps: =
        SEND_STRING("=");
    }
}
// Funciones específicas para cada diagnóstico
void diag_w_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("]w");  // 1 tap: siguiente warning
    } else if (state->count == 2) {
        SEND_STRING("[w");  // 2 taps: warning anterior
    }
}

void diag_d_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("]d");  // 1 tap: siguiente diagnóstico
    } else if (state->count == 2) {
        SEND_STRING("[d");  // 2 taps: diagnóstico anterior
    }
}

void diag_e_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("]e");  // 1 tap: siguiente error
    } else if (state->count == 2) {
        SEND_STRING("[e");  // 2 taps: error anterior
    }
}

void diag_t_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("]t");  // 1 tap: siguiente trouble
    } else if (state->count == 2) {
        SEND_STRING("[t");  // 2 taps: trouble anterior
    }
}
// Función para WIN+TAB / Layer 5
void win_tab_l5_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            // Hold: activar capa 5
            layer_on(5);
        } else {
            // Tap: Alt+Tab
            register_code(KC_LGUI);
            tap_code(KC_TAB);
            unregister_code(KC_LGUI);
        }
    }
}

void win_tab_l5_reset(tap_dance_state_t *state, void *user_data) {
    // Desactivar capa 5 al soltar
    layer_off(5);
}
// =================== Tap Dance Actions ===================
tap_dance_action_t tap_dance_actions[] = {
    [TD_VIM_GCC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vim_gcc_finished, vim_gcc_reset),
    [TD_VIM_XX] = ACTION_TAP_DANCE_FN(vim_xx_finished),
    [TD_DIAG_W] = ACTION_TAP_DANCE_FN(diag_w_finished),
    [TD_DIAG_D] = ACTION_TAP_DANCE_FN(diag_d_finished),
    [TD_DIAG_E] = ACTION_TAP_DANCE_FN(diag_e_finished),
    [TD_DIAG_T] = ACTION_TAP_DANCE_FN(diag_t_finished),
    [TD_WIN_TAB_L5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_tab_l5_finished, win_tab_l5_reset), // ← AGREGAR
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
            case MULTIMEDIA :
                oled_write("MULTIMEDIA", false);
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
