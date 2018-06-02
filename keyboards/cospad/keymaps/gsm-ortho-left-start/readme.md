COSPAD
===

Starting point for Left Hand keymap when used as keyboard (usb port to the right)

I am creating this as a gamepad so I am only creating a left hand.


## Enter program mode (reset)

   Looking from the rear with the USB port away from you.
   Just to the right of the top right LED there is a vertical row of 6 pins
   Short the top 2 pins with tweezers, while the keyboard is powered on
   These 2 pins are labeled as RST when viewed from the front, but not visible if a plate was used to mount switches
   
### To Flash
   make cospad:gsm-ortho-left-start:dfu



Make example for this keyboard (after setting up your build environment):

    make cospad:gsm-ortho-left-start
    

See QMK docs to setup your environment before flashing
