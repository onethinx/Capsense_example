# Capsense on the Onethinx Core Module
This is the Example code for Capsense on the Onethinx Core (use in conjunction with the VSCode_OnethinxPack).

## Hardware setup
1. Connect Cmod (a 2.2nF capacitor) to IO3
    Remind that P7.7 and P10.2 are interconnected internally: if using the Cmod on P7.7, P10.2 has to be unconfigured and unconnected
1. Connect a 'capsense button' to P10.0

## Project description
The project is set-up and configured using PSoC Creator. The PSoC Creator project can be found inside "PSoC Creator Project' folder. The [Onethinx UDB porting tool](https://github.com/onethinx/UDB-porting-tool) is used for porting the Capsense settings to the VS Code project.

This project uses Cypress's SmartSense (full autotune) and might need (additional/manual) tuning. Consult the Capsense datasheet for more information.

## Preparation
1. Make sure you have the VS Code IDE & Dependencies Pack setup done:
    - For Windows: [VSCode_OnethinxPack_Windows](https://github.com/onethinx/VSCode_OnethinxPack_Windows)
    - For Linux: [VSCode_OnethinxPack_Linux](https://github.com/onethinx/VSCode_OnethinxPack_Linux)
    - For MacOS: [VSCode_OnethinxPack_MacOS](https://github.com/onethinx/VSCode_OnethinxPack_MacOS)
1. Clone or download the project to your local machine.
## Start coding and debugging :-)
1. Start VS Code
1. Load the project: File >> Open (Folder) >> Select the folder of the project >> OK
1. Navigate to source/OnethinxCore/LoRaWAN_keys.h and fill in your LoRaWAN keys.
1. Click "⚙︎ Build" in the status bar to build the project.
    * if it fails to build, try "Clean Reconfigure" + "Clean Rebuild" from the Cmake extension (left bar).
    * if it still fails, try deleting the contents of the 'build/' folder.
1. Debug the project using the (Cortex-) Debug extension from the left bar.
    * depending on your debug adapter select "CM4 Debug Kitprog" or "CM4 Debug J-Link" and press 'start'.

A loop where the char-values of 'Hello World' will be sent every 10s is then entered.
If not joined -this may take a long while-, the blue LED will blink fast forever.

