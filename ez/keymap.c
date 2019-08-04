#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_extras/keymap_norwegian.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TAB_LSFT MT(MOD_LSFT, KC_TAB)
#define CPS_LSFT MT(MOD_LSFT, KC_CAPSLOCK)

#define LPRN S(KC_8)
#define LBRK S(A(KC_8))
#define LBRC A(KC_8)
#define RPRN S(KC_9)
#define RBRK S(A(KC_9))
#define RBRC A(KC_9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | '    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Å  | Entr |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tb/S |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Ø  |   Æ  |   ,  | ./Rs |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Cp/S | Ctrl | Alt  | Cmd  |  Lwr |    Space    |  Rse | Left | Down |  Up  | Rght |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_grid(
    KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    NO_AA,   KC_ENT,
    TAB_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  NO_OSLH, NO_AE,   KC_COMM, KC_DOT,
    CPS_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      |   #  |   &  |      |   {  |   ´  |   =  |   }  |      |   |  |   ^  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   %  |   !  |   <  |   (  |   *  |   @  |   )  |   >  |   /  |   ¨  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   $  |   ?  |      |   [  |   `  |   "  |   ]  |      |   \  |   ~  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
    _______, KC_HASH, S(KC_6),    _______, LBRK,    KC_EQL,    S(KC_0), RBRK,    _______,    A(KC_7),    NO_CIRC, _______,
    _______, KC_PERC, KC_EXLM,    KC_NUBS, LPRN,    NO_ASTR,   KC_BSLS, RPRN,    S(KC_NUBS), S(KC_7),    KC_RBRC, _______,
    _______, KC_DLR,  S(KC_MINS), _______, LBRC,    S(KC_EQL), S(KC_2), RBRC,    _______,    S(A(KC_7)), NO_TILD, _______,
    _______, _______, _______,    _______, _______, _______,   _______, _______, KC_MNXT,    KC_VOLD,    KC_VOLU, KC_MPLY
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   0  |   1  |   2  |   3  |      |      |      |      |      |      |   +  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   4  |   5  |   6  |      |      | Left | Down |  Up  | Rght |   -  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   7  |   8  |   9  |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Prev | Bri- | Bri+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
    KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,  KC_MINS, _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_SLSH, _______,
    _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_SLCK,  KC_PAUS, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  KC_F1,  KC_F2,  KC_F3,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  KC_F4,  KC_F5,  KC_F6,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, KC_F7,  KC_F8,  KC_F9,
    _______, _______, _______, _______, _______, RGB_TOG, RGB_TOG, _______, _______,  KC_F10, KC_F11, KC_F12
  )

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
