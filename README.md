# custom_qmk_keymap

Custom QMK keymaps for several keyboards

## Implemented keymaps

- acheron/apollo/87h/delta/keymaps/indicator [README](delta/keymaps/indicator/README.md)

## How to build custom firmware

### Apollo87H-delta LED indicator

```bash
cp -r delta $QMK_FIRMWARE_ROOT/keyboards/acheron/apollo/87h
qmk compile -j 0 -kb acheron/apollo/87h/delta -km indicator
```
