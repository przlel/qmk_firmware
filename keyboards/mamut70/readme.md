# mamut70

A 70-key split keyboard: two halves of 5 rows by 7 columns, each driven by an RP2040-Zero, with one WS2812 LED per half.

* Keyboard Maintainer: [Przemysław](https://github.com/przlel)
* Hardware Supported: RP2040-Zero (one per half)
* Hardware Availability: aliexpress.com, amazon.com

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb mamut70/rp2040 -km via

Without a local QMK environment, compile with Docker from the `qmk_firmware` root:

    docker run --rm -v "$(pwd)":/qmk_firmware qmkfm/qmk_cli qmk compile -c -kb mamut70/rp2040 -km via

The firmware file `mamut70_rp2040_via.uf2` appears in the `qmk_firmware` root.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key, Escape) and plug in the keyboard
* **Double tap reset**: Press the reset button of the RP2040-Zero twice within 500 ms
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (bottom right key of the `_NAV` layer)
