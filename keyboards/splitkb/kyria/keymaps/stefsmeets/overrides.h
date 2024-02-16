#include QMK_KEYBOARD_H

const key_override_t delete_key_override = 
	ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);  // Shift bs is del

const key_override_t dot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);  // Shift . is ?

const key_override_t comm_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM); // Shift , is !

const key_override_t coln_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN); // Shift : is ;

const key_override_t slsh_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS); // Shift back slash is forward slash

const key_override_t spc_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_UNDS); // Shift space is _

const key_override_t unds_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINS); // Shift _ is -

const key_override_t** key_overrides = (const key_override_t*[]){
	// &delete_key_override,
    &dot_key_override,
    &comm_key_override,
    &coln_key_override,
    &slsh_key_override,
    // &spc_key_override,
    &unds_key_override,
    NULL  // Null terminate the array of overrides!
};
