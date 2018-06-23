# GreenShadowMaker Ergodox Infinity Layout

Started with: Input Club ErgoDox Infinity Layout

Took visualizer from dudeofawesome, 


## Features

Base Layers

- QWERTY
- Function Keys
- Numpad

## Building and flashing

1. Put your board in DFU mode with either the button on the bottom, or with a software key in your current firmware
2. Flash left half:
    ```bash
    make ergodox_infinity:greenshadowmaker:dfu-util
    ```
3. Flash right half:
    ```bash
    make ergodox_infinity:greenshadowmaker:dfu-util MASTER=right
    ```
