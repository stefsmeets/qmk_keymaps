# My QMK keymaps

This repository hosts my QMK keymaps:

- [splitkb/kyria/rev3:stefsmeets](./keyboards/splitkb/kyria/keymaps/stefsmeets)

## How to build locally

1. Run the normal `qmk setup` in the qmprocedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
    - Note: This command must be run in the `qmk_firmware` directory
1. Clone this repository
    - `git clone https://github.com/stefsmeets/qmk_keymaps`
1. Set global userspace path: 
    - `cd qmk_keymaps`
    - `qmk config user.overlay_dir="$(realpath .)"`
    - Note: you MUST be located in the cloned userspace location for this to work correctly
    - Note: This will be automatically detected if you've `cd`ed into your userspace repository, but the above makes your userspace available regardless of your shell location.
1. Compile normally: 
    - `qmk compile -kb splitkb/kyria/rev3 -km stefsmeets` or `make splitkb/kyria/rev3:stefsmeets`
    - Note: This command must be run in the `qmk_firmware` directory
