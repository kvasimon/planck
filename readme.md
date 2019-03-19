# Semonje Planck Layout
My OLKB Planck Light keyboard layout. It relies on the standard Norwegian Mac layout, in order for it to work properly.

![What it looks like](/thumbnail.jpg)

> Psst – the photo isn't entirely updated. Check out the actual keymap file for the current layout!

## General idea
Mainly, I want my often used modifier keys to be easily accessible, which is why they're placed at the middle. In my other layers, I keep keys often used for programming close and systematic.

## Layers
At the moment, I'm using four different layers:
- **Main**: QWERTY layout with additional Norwegian characters.
- **Lower**: Useful keys for programming, like parantheses, brackets, etc.
- **Raise**: Number pad and arrows in VIM style.
- **Adjust**: Function keys and settings layer for resetting the keyboard, controlling RGB lights, etc.

## Build
Enable debug mode on your keyboard and run
``` bash
# In github.com/qmk/qmk_firmware
make planck/light:semonje:dfu
```

Otherwise, refer to the [Planck keyboard](https://github.com/qmk/qmk_firmware/tree/master/keyboards/planck) at [QMK](https://github.com/qmk/qmk_firmware) for setup and general build instructions.
