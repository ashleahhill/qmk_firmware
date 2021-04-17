#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

char wpm[10];

void oled_task_user(void) {
    sprintf(wpm, "WPM: %03d", get_current_wpm());

    // Host Keyboard Layer Status
    oled_write_P(PSTR("      breathe. \n"), false);
    oled_write_P(PSTR(" Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR(" "), false);
    oled_write(wpm, false);
}
#endif
