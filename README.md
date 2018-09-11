# Arduino-Infineon-SmartSwitches
Some Arduino code for Infineon Smart Switches and ProFETs.

Infineon have made their demo code available as open source, but it is code that has been generated using their [DAVE](https://infineoncommunity.com/dave-download_ID645) development tool.

The purpose of this project is to provide very simple interfaces to the devices via C++ objects.

These have been developed using Infineon's evalution sheilds:

* ProFET [24V_SHIELD_BTT6030](https://www.infineon.com/cms/en/product/evaluation-boards/24v_shield_btt6030/)
* Smart Switch [SHIELD_BTS50010-1TAD](https://www.infineon.com/cms/en/product/evaluation-boards/shield_bts50010-1tad/)

The `ProFET` directory contains chip drivers for:

* [BTT6020-1EKA](https://www.infineon.com/dgdl/Infineon-BTT6020-1EKA-DS-v01_01-EN.pdf?fileId=5546d4625a888733015aa390dd8a0fdc)
* [BTT6030-2EKA](https://www.infineon.com/dgdl/Infineon-BTT6030-2EKA-DS-v01_01-EN.pdf?fileId=5546d4625a888733015aa387a48c0fd8)

The `SmartSwitch` directory contains the chip driver for:

* [BTS50010-1TAD](https://www.infineon.com/dgdl/Infineon-BTS50010-1TAD-DS-v01_01-EN.pdf?fileId=5546d462576f34750157c38810ca55cd)

The `Sheilds` Directory contains C++ objects for the two Infineon Evaluation Boards listed above.