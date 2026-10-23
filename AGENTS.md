# AGENTS.md - QMK Firmware Development Guidelines

This document provides guidelines for AI agents working on QMK firmware code.

## Build Commands

### Firmware Compilation
```bash
# Compile a specific keyboard and keymap
qmk compile -kb <keyboard_name> -km <keymap_name>

# Compile with parallel jobs
qmk compile -j 0 -kb <keyboard_name>

# Create compilation database (for IDE support)
qmk compile --compiledb
```

### Flashing Firmware
```bash
# Flash to keyboard with default bootloader
qmk flash -kb <keyboard_name> -km <keymap_name>

# Flash with specific bootloader
qmk flash -kb <keyboard_name> -km <keymap_name> -bl <bootloader>
```

### Linting and Formatting
```bash
# Lint keyboard configuration
qmk lint -kb <keyboard_name>

# Format JSON files
qmk format-json -i path/to/info.json
```

### Testing
```bash
# Run all tests
make test:all

# Run single test group (supports colons for specificity)
make test:tap_dance          # Run tap_dance tests
make test:retro_shift:tap_hold_configurations  # Specific test

# Debug tests with console output
make test:all DEBUG=1
```

Python tests:
```bash
nose2 -v
```

## Code Style Guidelines

### C Code Conventions

**Indentation**: 4 spaces (soft tabs). Never use hard tabs.

**Brace Style**: Modified One True Brace Style
```c
if (condition) {
    return true;
} else {
    return false;
}
```

**Comments**: Use C-style `/* */` comments. Explain "why", not "what". Be generous with context.

**Line Wrapping**: Maximum 76 columns when wrapping.

**Header Guards**: Use `#pragma once` instead of `#ifndef` guards.

**Preprocessor Directives**: Prefer `#if defined(DEFINED)` form.

### Auto-formatting

Use clang-format with the `.clang-format` configuration:
```bash
clang-format -style=file -i source_file.c
```

Wrap LAYOUT macros in disable/enable comments:
```c
// clang-format off
#define LAYOUT(...) { ... }
// clang-format on
```

### Python Code Conventions

- Indentation: 4 spaces
- Line Length: 256 characters
- Linting: `flake8`, Formatting: `yapf -i filename.py`
- max_complexity: 16 (setup.cfg)

### File Naming

All filenames and directories must be lowercase. Exceptions: upstream sources (LUFA, ChibiOS) or core files with valid justification.

## License and Headers

All `.c` and `.h` files require GPL-compatible license headers:
```c
// Copyright 2024 Your Name (@yourgithub)
// SPDX-License-Identifier: GPL-2.0-or-later
```

Simple assignment-only `rules.mk` files are exempt.

## QMK Best Practices

**Include Guards**: Use `#pragma once` in headers.

**Hardware Access**: No low-level GPIO/I2C/SPI register access. Must use QMK abstractions.

**Timing Functions**:
- Use `wait_ms()` instead of `_delay_ms()`
- Remove `#include <util/delay.h>`
- Use `timer_read()`, `timer_read32()` from `timer.h`

**Data-Driven Configuration**: Prefer `info.json` and `keyboard.json` over `config.h`.

## Branch and PR Guidelines

**Target Branches**:
- New keyboards → `master`
- All other changes → `develop`

**Scope**: PRs should contain the smallest set of modifications for a single change.

**Source Branches**: Never submit from `master` branch; use feature branches.

## Keymap Standards

**Includes**: Prefer `#include QMK_KEYBOARD_H` over specific board files.

**Enums**: Use layer enums over `#define`s.

**Custom Keycodes**: First entry must be `QK_USER`.

**Default Keymaps**: Should be pristine (minimal features).

**VIA**: Keymaps should NOT enable VIA in PRs.

## Keyboard Implementation Standards

**info.json/keyboard.json**:
- Run `qmk format-json -i` before submitting
- Validate with `qmk lint -kb <keyboard_name>`
- Must include: valid URL, maintainer, USB VID/PID, microcontroller, bootloader

**rules.mk**:
- Remove deprecated features: `MIDI_ENABLE`, `FAUXCLICKY_ENABLE`, `HD44780_ENABLE`
- Remove size comments like `(-/+size)`
- Keymap-only features (COMBO_ENABLE, ENCODER_MAP_ENABLE) belong in keymap, not keyboard

**config.h (keyboard level)**:
- No `#define DESCRIPTION`
- No user preference defines (belong in keymap)
- No default value re-definitions
- No commented-out code
- Minimal boot code only

**Keyboard C Files**:
- Remove empty weak-defined functions
- `CUSTOM_MATRIX = lite` preferred over full custom matrix

## References

- Full PR checklist: `.github/copilot-instructions.md`
- Coding conventions: `docs/coding_conventions_c.md`
- Unit testing: `docs/unit_testing.md`
- CLI commands: `docs/cli_commands.md`
