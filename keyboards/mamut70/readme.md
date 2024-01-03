# mamut70

![mamut70](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Przemysław](https://github.com/przlel)
* Hardware Supported: RP2040-Zero
* Hardware Availability: aliexpress.com, amazon.com

Make example for this keyboard (after setting up your build environment):

    make mamut70/rp2040:via

with podma/docker

podman run -it  -v $(pwd):/qmk_firmware qmkfm/qmk_cli qmk compile -c -kb mamut70/rp2040 -km via

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
