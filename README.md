# custom_qmk_keymap

Custom QMK keymaps for several keyboards

## Implemented keymaps

- acheron/apollo/87h/delta/keymaps/indicator [README](delta/keymaps/indicator/README.md) [Download](https://github.com/dreamingjudith/custom_qmk_keymap/releases/tag/apollo87h-delta-indicator-v0)
- massdrop/thekey_v2/keymaps/per-key-rgb [README](thekey_v2/keymaps/per-key-rgb/README.md) [Download](https://github.com/dreamingjudith/custom_qmk_keymap/releases/tag/massdrop-the-key-v2-per-key-rgb-v0)
- ikki68_aurora/keymaps/led [README](custom_qmk_keymap/ikki68_aurora/keymaps/led/readme.md)

### Official indicator update for Apllo87H

[Gondolindrim](https://github.com/Gondolindrim) has updated firmware to activate RGB indicator. Please check out [this link](https://discord.com/channels/743801649377574924/811452141570752523/1114928412973342840).

## How to build custom firmware

### Apollo87H-delta LED indicator

```bash
cp -r delta $QMK_FIRMWARE_ROOT/keyboards/acheron/apollo/87h
qmk compile -j 0 -kb acheron/apollo/87h/delta -km indicator
```

### The Key v2 Per-key RGB

```bash
cp -r thekey_v2 $QMK_FIRMWARE_ROOT/keyboards/massdrop
qmk compile -j 0 -kb massdrop/thekey_v2 -km perkey-rgb
```

### Ikki68 Aurora LED toggling

```bash
cp -r ikki68_aurora $QMK_FIRMWARE_ROOT/keyboards/wuque
qmk compile -j 0 -kb ikki68_aurora -km led
```
