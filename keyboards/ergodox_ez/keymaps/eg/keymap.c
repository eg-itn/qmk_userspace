#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"
#include "version.h"

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    SMENU, // Shift+Menu(App)
    CTRLZ, // Ctrl+Z
    CTRLX, // Ctrl+X
    CTRLC, // Ctrl+C
    CTRLV, // Ctrl+V
    SHRX, // ShareX capture shortcut(Shift+Win+A)
    BNDC, // Bandicam capture shortcut(Ctrl+Shift+Alt+S)
    TURBO,  // Mouse Click Turbo
    TGTP,  // Toggle Always on Top(Ctrl+Win+T)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYER0
 *
 *` ,-------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | MO(1)|           | MO(1)|   Y  |   U  |   I  |   O  |   P  |  Enter |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | 2|ESC  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+------| MO(1)|           | MO(1)|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | SLSH | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl  | Gui  | Alt  | Alt  | MO(3)|                                       | MO(3)| MO(4)| MO(1)|  App | Ctrl |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  | Space|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Tab  |Backsp|
 *                                 |      |ace   | End  |       | PgDn |      |ace   |
 *                                 `--------------------'       `--------------------'
 */
[_LAYER0] = LAYOUT_ergodox_pretty(
  // left hand
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT, KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(1),   MO(1),   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    LT(2,KC_ESC), KC_A, KC_S,  KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(1),   MO(1),   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(3),                                       MO(3),   MO(4),   MO(1),   KC_APP,  KC_RCTL,
                                        KC_SPC,  KC_SPC,                     KC_LALT, KC_SPC,
                                                 KC_HOME,                    KC_PGUP,
                                KC_SPC, KC_BSPC, KC_END,                     KC_PGDN, KC_TAB, KC_BSPC
),
/* LAYER1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F12  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |   (  |   )  |   =  |      |           |      |      │PrtScn│ ScrLk│ Paus │      │        │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      │  [   │  ]   │  \   │Enter |------|           |------|      │  Ins │ Home │ PgUp │      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        │ CTRLZ│ CTRLX│ CTRLC│ CTRLV│      |      |           |      |      │  Del │  End │ PgDn │      │        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LAYER1] = LAYOUT_ergodox_pretty(
  // left hand
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_ENT,                    KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
    KC_TRNS, CTRLZ,   CTRLX,   CTRLC,   CTRLV,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        RGB_MOD, KC_TRNS,                   RGB_TOG, RGB_M_P,
                                                 KC_TRNS,                   KC_TRNS,
                               RGB_VAD, RGB_VAI, KC_TRNS,                   KC_TRNS, RGB_HUD, RGB_HUI
),
/* LAYER2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * │        │ MS B1│ MS B3│ MS B2│      │      │      │           |      |      | # Lk │   /  │   *  │  -   │   +    │
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * │ Esc    │WH Lft│MS Up │WH Lft│ WH Up│      │      │           |      |      | 7    │  8   │  9   │   +  │ Caps   │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │        │MS Lf │MS Dw │MS Rgt│ WH Dw│      │------│           |------|      | 4    │  5   │  6   │   +  │        │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │Enter   |      |      |      |      |      |      |           |      |      │  1   │  2   │  3   │  =   │        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      │ Acl 0│ Acl 0│      |                                       │  0   │  0   │   .  │ Entr │      │
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Acl 2|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LAYER2] = LAYOUT_ergodox_pretty(
  // left hand
    KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,
    KC_ESC,  KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_CAPS,
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,                   KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
    KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL0, KC_TRNS,                                     KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
                                        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
                                                 KC_TRNS,                   KC_TRNS,
                               KC_ACL2, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_WBAK
),
/* LAYER3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * │  F12   │  F1  │  F2  │  F3  │  F4  │  F5  │      │           |      |  F6  │  F7  │  F8  │  F9  │  F10 │  F11   │
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * │        │      │      │  Up  │      │ TGTP │      │           |      |      |      │  Up  │      │      │        │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │        │ TURBO│ Left │ Down │ Right│      │------│           |------|      │ Left │ Down │ Right│      │        │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │        │ APP  │      │ SHRX │ BNDC │      │      |           |      │      │      │      │      │ APP  │        │
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      │      │      │      |                                       │      │      │      │      │      │
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LAYER3] = LAYOUT_ergodox_pretty(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, TGTP,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, TURBO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, SMENU,   KC_TRNS, SHRX,    BNDC,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SMENU,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
                                                 KC_TRNS,                   KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_WBAK

    ),
/* LAYER4
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * │        │      │      │      │      │      │      │           |      |      │      │      │Ld Tog│ Brt- │ Brt+   │
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * │        │      │      │      │      │      │      │           |      |      |      |      │ Mute │ Vol- │ Vol+   │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │        │      │      │      │      │      │------│           |------|      │      │      │      |      │        │
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * │        │      │      │      │      │      │      |           |      │      │      │      │      │      │        │
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      │      │      │      |                                       │      │      │      │      │ Reset│
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LAYER4] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_BRID, KC_BRIU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
                                        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
                                                 KC_TRNS,                   KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_WBAK
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SMENU:
    // If key is being pressed, send shift + Menu
       if (record->event.pressed) {
         register_code(KC_LSFT);
         tap_code(KC_APP);
         unregister_code(KC_LSFT);
       }
       break;

    case CTRLZ:
    // If key is being pressed, send ctrl + z
         if (record->event.pressed) {
            register_code(KC_LCTL);
            tap_code(KC_Z);
            unregister_code(KC_LCTL);
         }
        break;

    case CTRLX:
    // If key is being pressed, send ctrl + x
        if (record->event.pressed) {
            register_code(KC_LCTL);
            tap_code(KC_X);
            unregister_code(KC_LCTL);
        }
        break;

    case CTRLC:
    // If key is being pressed, send ctrl + c
        if (record->event.pressed) {
            register_code(KC_LCTL);
            tap_code(KC_C);
            unregister_code(KC_LCTL);
        }
        break;

    case CTRLV:
    // If key is being pressed, send ctrl + v
        if (record->event.pressed) {
            register_code(KC_LCTL);
            tap_code(KC_V);
            unregister_code(KC_LCTL);
        }
        break;

    case SHRX:
    // If key is being pressed, send shift + win + a
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_LGUI);
            tap_code(KC_A);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
        }
        break;

    case BNDC:
    // If key is being pressed, send ctrl + shift + alt + s
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_LALT);
            tap_code_delay(KC_S, 100);
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
        break;

    case TGTP:
    // If key is being pressed, send ctrl + shift + alt + t
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LGUI);
            tap_code_delay(KC_T, 100);
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
        }
        break;

  }

  // MOUSE TURBO
  if (!process_mouse_turbo_click(keycode, record, TURBO)) {
     return false;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
