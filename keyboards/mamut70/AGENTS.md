# AGENTS.md - Mamut70 Keyboard Development

This document provides guidelines for AI agents working on the Mamut70 keyboard.

## Build Commands

### Docker Compilation (Recommended)

**IMPORTANT**: Always use Docker image tag `qmkfm/qmk_cli:1.2.0` or later. Newer versions (1.2.0+) use `qmk compile` subcommand.

```bash
# From qmk_firmware root directory (use -i instead of -it for non-interactive terminals)
docker run -i -v $(pwd):/qmk_firmware qmkfm/qmk_cli:1.2.0 qmk compile -c -kb mamut70/rp2040 -km via

# With specific keymap
docker run -i -v $(pwd):/qmk_firmware qmkfm/qmk_cli:1.2.0 qmk compile -c -kb mamut70/rp2040 -km <keymap_name>
```

### Direct Compilation (if QMK CLI installed locally)
```bash
qmk compile -kb mamut70/rp2040 -km via
```

### Flashing
```bash
# Flash with default bootloader
docker run -i -v $(pwd):/qmk_firmware qmkfm/qmk_cli:1.2.0 qmk flash -kb mamut70/rp2040 -km via
```

### Linting
```bash
qmk lint -kb mamut70/rp2040
```

## Hardware Information

- **Microcontroller**: RP2040-Zero
- **Bootloader**: RP2040 bootloader
- **Features**: RGB lighting (WS2812), split keyboard support

## Keyboard Structure

```
keyboards/mamut70/
├── AGENTS.md           # This file
├── readme.md           # Keyboard documentation
├── config.h            # Base configuration
├── mamut70.c           # Keyboard implementation
├── mamut70.h           # Keyboard layout definitions
├── keymaps/
│   └── via/            # VIA-enabled keymap
│       └── keymap.c    # Main keymap file (778 lines)
└── rp2040/
    ├── config.h        # MCU-specific config
    ├── info.json       # Keyboard JSON definition
    ├── mcuconf.h       # MCU configuration
    └── rules.mk        # Build rules
```

## Keymap Analysis Summary

### Layers (8 total)
| Layer | Name | Purpose |
|-------|------|---------|
| `_BASE` | Base | Default alphanumeric layout |
| `_PC` | PC | Alternative PC-optimized layout |
| `_PC_CTR` | PC CTR | Control layer for PC |
| `_PROG` | Prog | Programming functions |
| `_NUM_ROW` | Num Row | Number row functions |
| `_MOUSE` | Mouse | Mouse key functions |
| `_NUMPAD` | Numpad | Numeric keypad |
| `_NAV` | Nav | Navigation cluster |

### Key Features Implemented

1. **OS Detection** (`os_detection.h`)
   - Auto-detects: Linux, Windows, macOS/iOS
   - Dynamically adjusts key behavior per OS
   - Custom keycode `CKC_SUPER` (KC_F20) for context-aware modifiers

2. **Tap Dance** (9 custom tap-dance keys)
   - `GRV_TD`: ` / ~
   - `MINS_TD`: - / _ / `->{}` (triple tap)
   - `SLSH_TD`: / / ?
   - `LBRC_TD`: [ / {
   - `RBRC_TD`: ] / }
   - `BSLS_TD`: \ / |
   - `QUOTE_TD`: ' / "
   - `CMD_TD`: Multi-function (space/super/NAV)
   - `MINS_TD`: - / _ with `->{}` macro

3. **Mod-Tap Keys**
   - `MT(MOD_LSFT, KC_S)` - Shift + S when held
   - `MT(MOD_RALT, KC_D)` - Alt + D when held
   - `MT(MOD_LGUI, KC_SPC)` - Cmd + Space when held

4. **RGB Lighting** (per-layer colors)
   - `_BASE`: Green (0,200,0)
   - `_PROG`: Blue (0,128,255)
   - `_NAV`: Blue (0,0,255)
   - `_NUMPAD`: Cyan (0,255,255)
   - `_PC`: Dark green (0,77,0)
   - `_PC_CTR`: Gray (77,77,77)

5. **Caps Word** - Custom implementation with extended keycodes

6. **Super Key System** - Context-aware modifier system
   - Adjusts behavior based on detected OS
   - Maps keys to different modifiers per OS

## Code Style Notes

### Existing Code Patterns

- **Enums**: Layer names use `_NAME` format (e.g., `_BASE`, `_NAV`)
- **Tap Dance**: Uses `ACTION_TAP_DANCE_FN_ADVANCED` for complex behaviors
- **Comments**: C-style `/* */` with descriptive context
- **Indentation**: 4 spaces

### Recommended Changes for PRs

1. Remove commented-out code blocks
2. Consider extracting tap-dance handlers to separate functions
3. The `super_key_to_mask` and `gui_mask_actions` structures could be refactored for clarity

## Bootloader Entry

1. **Bootmagic**: Hold key at (0,0) while plugging in
2. **Physical reset**: Press button on PCB
3. **Keycode**: Press key mapped to `QK_BOOT`

## References

- Root AGENTS.md: `/qmk_firmware/AGENTS.md`
- QMK Docs: https://docs.qmk.fm/
- VIA Configuration: https://caniusevia.com/

---

# Multi-Operating System Support Analysis

This section provides a comprehensive analysis of the OS detection and adaptation system implemented in the Mamut70 keymap.

## Overview

The Mamut70 implements an intelligent **OS Detection** system using QMK's `os_detection.h` module. This system:

1. **Auto-detects** the host operating system on boot
2. **Dynamically remaps** key behaviors based on the detected OS
3. **Supports** Linux, Windows, and macOS (iOS maps to macOS)
4. **Maintains** consistent user experience across different platforms

## Supported Operating Systems

| OS | Enum Value | Notes |
|----|------------|-------|
| Linux | `OS_LINUX` | Primary development target |
| Windows | `OS_WINDOWS` | Standard Windows keybindings |
| macOS | `OS_MACOS` | Includes iOS detection fallback |
| iOS | `OS_IOS` | Mapped to macOS behavior |

## Detection Mechanism

### Initialization
```c
os_variant_t selected_os = OS_UNSURE;

bool process_detected_host_os_user(os_variant_t os) {
    selected_os = (os == OS_IOS) ? OS_MACOS : os;  // iOS uses macOS behavior
    return true;
}
```

QMK calls `process_detected_host_os_user()` once the guess has been stable
for `OS_DETECTION_DEBOUNCE` ms (250 ms) and again whenever it changes, so a
late USB setup packet can still correct an early wrong guess.

### Core fix for macOS
macOS 15.7 sends the wLength sequence `02 10 02 0E 02 42 04 FF FF`. The
stock Windows rule (`cnt_ff >= 2 && cnt_04 >= 1`) matched it first, so the
Mac was detected as Windows. Upstream commit `d3069760d7` (qmk#26303, on
`develop`) adds `cnt_02 < 2` to that rule; it is cherry-picked into this
fork. Test: `TestChibiosMacosWithEarly04Packet`, run with
`make test:os_detection`.

### OS indicator LED (right half)
- macOS/iOS: white, Windows: blue, Linux: green, all at 153/255 (60%)
- Undetected: off
- Each half drives only its own LED. `SPLIT_DETECTED_OS_ENABLE` (keymap
  `config.h`) syncs the OS to the slave, and `housekeeping_task_user()`
  on the right half updates the LED. The left LED shows the layer color.
- Both halves must run the same build, because the OS sync adds a split
  transaction.

## Super Key System (CKC_SUPER)

The core of OS adaptation is the **Super Key** system - a context-aware modifier triggered by `CKC_SUPER` (KC_F20).

### Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    Super Key System                         │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌──────────────┐    ┌──────────────────┐    ┌──────────┐ │
│  │ CKC_SUPER    │───>│ find_mode()      │───>│ Modifier │ │
│  │ (KC_F20)     │    │ [OS-specific]    │    │ Applied  │ │
│  └──────────────┘    └──────────────────┘    └──────────┘ │
│         │                     │                      │      │
│         v                     v                      v      │
│  SUPER_ACTIVE flag    lookup in            register/       │
│                       super_key_to_mask    unregister_mods  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Mode Mapping Table

| Keycode | Linux | Windows | macOS |
|---------|-------|---------|-------|
| `KC_TAB` | `MOD_LALT` | `MOD_LALT` | (default) |
| `KC_GRV` | `MOD_LALT` | `MOD_LALT` | (default) |
| `KC_C` | `MOD_LCTL` | (default) | (default) |
| `KC_V` | `MOD_LSFT` | (default) | (default) |
| `KC_SPACE` | `MOD_EMPTY` | (default) | (default) |
| `CKC_SUPER` | `MOD_LCTL` | `MOD_LCTL` | `MOD_LGUI` |

### Default Modifier
- **Linux**: `MOD_LGUI` (Windows key / Command)
- **Windows**: `MOD_LGUI` (Windows key)
- **macOS**: `MOD_LGUI` (Command/⌘)

### Implementation Details

```c
Mode super_key_to_mask[][6] = {
    [OS_LINUX] = {
        { KC_TAB, MOD_LALT },
        { KC_GRV, MOD_LALT },
        { KC_C, MOD_LCTL },      // Ctrl+C for copy
        { KC_V, MOD_LSFT },      // Shift+V for paste (vim-style)
        { KC_SPACE, MOD_EMPTY }, // Space without modifiers
        { CKC_SUPER, MOD_LCTL }  // Super acts as Ctrl
    },
    [OS_WINDOWS] = {
        { KC_TAB, MOD_LALT },
        { KC_GRV, MOD_LALT },
        { CKC_SUPER, MOD_LCTL }  // Super acts as Ctrl
    },
    [OS_MACOS] = {
        { CKC_SUPER, MOD_LGUI }  // Super acts as Cmd
    }
};
```

## Key Action System

Beyond modifier remapping, the system supports **OS-specific key actions** via the `Action` structure.

### Action Structure
```c
typedef struct {
    os_variant_t os;
    uint16_t key_code;
} Action;
```

### GUI Mask Actions
Maps key combinations for GUI modifier behavior:

```c
Action gui_mask_actions[][3] = {
    [KC_SPC] = {{OS_LINUX, KC_LGUI },{OS_WINDOWS, KC_LGUI }},
    [KC_C] =  {{OS_LINUX, KC_INS }},   // Linux: Ctrl+Insert = Copy
    [KC_V] =  {{OS_LINUX, KC_INS }}    // Linux: Shift+Insert = Paste
};
```

### Default Actions
OS-specific key bindings for navigation:

```c
Action default_actions[][3] = {
    [KC_HOME] = {{OS_MACOS, LCTL(KC_A)}},  // Ctrl+A = Home (beginning of line)
    [KC_END] = {{OS_MACOS, LCTL(KC_E)}}   // Ctrl+E = End (end of line)
};
```

## Processing Pipeline

```
keypress ──> process_super_action()
                          │
                          ├── CKC_SUPER pressed? ──> Activate SUPER_ACTIVE
                          │
                          ├── SUPER_ACTIVE?
                          │   ├── find_mode(keycode) ──> Get OS-specific modifier
                          │   ├── register_mods() ──> Apply modifier
                          │   └── process_key_action() ──> Handle custom actions
                          │
                          └── Return true/false (handled?)
```

### process_super_action() Flow

```c
bool process_super_action(uint16_t keycode, bool pressed) {
    // 1. Handle CKC_SUPER key itself
    if (keycode == CKC_SUPER) {
        if (!pressed) {
            // Deactivate: unregister any pending modifiers
            uint8_t prev_mode = find_mode(CKC_SUPER, super_key_to_mask);
            if (prev_mode != MOD_EMPTY && mod_state & prev_mode) {
                unregister_mods(prev_mode);
            }
        }
        SUPER_ACTIVE = pressed;
    }

    // 2. When Super is active, remap subsequent keys
    if (SUPER_ACTIVE) {
        uint8_t current_mode = find_mode(keycode, super_key_to_mask);
        uint8_t prev_mode = find_mode(previous_key, super_key_to_mask);

        // Switch modifiers if needed
        if (prev_mode != MOD_EMPTY && prev_mode != current_mode) {
            unregister_mods(prev_mode);
        }

        // Apply new modifier
        if (current_mode != MOD_EMPTY && pressed) {
            register_mods(current_mode);
        }

        previous_key = keycode;
        return process_key_action(keycode, pressed, gui_mask_actions);
    }
    return true;
}
```

## Modifier Mode Constants

```c
const uint8_t MOD_EMPTY = 0;

#define MOD_LCTL   0x01
#define MOD_LSFT   0x02
#define MOD_LALT   0x04
#define MOD_LGUI   0x08
#define MOD_RCTL   0x10
#define MOD_RSFT   0x20
#define MOD_RALT   0x40
#define MOD_RGUI   0x80
```

## Usage in Keymap

### Layer Base - OS Adaptation in Action

```c
[_BASE] = LAYOUT_mamut_70(
    KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,
    DF(_BASE),                    // Layer switch
    DETECT_OS,                    // plain KC_F19, does not trigger detection
    KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_DEL,
    ...
    TD(CMD_TD),                   // Multi-function (Space/Super/NAV)
    LT(_NAV,KC_SPC),              // Nav layer or Space
    ...
)
```

**Key behaviors by OS:**

| Key | Linux | macOS | Windows |
|-----|-------|-------|---------|
| `KC_TAB` | Alt+Tab | Native Tab | Alt+Tab |
| `KC_GRV` (backtick) | Alt+` | Native ` | Alt+` |
| `CKC_SUPER` + `C` | Ctrl+C | Cmd+C | Ctrl+C |
| `CKC_SUPER` + `V` | Shift+Insert | Cmd+V | Ctrl+V |
| `KC_HOME` | Home | Cmd+Left | Home |
| `KC_END` | End | Cmd+Right | End |

## Adding New OS Support

To add support for a new OS (e.g., Android):

1. **Update super_key_to_mask**:
```c
[OS_ANDROID] = {
    { KC_TAB, MOD_LALT },
    { KC_C, MOD_LCTL },
    { KC_V, MOD_LSFT },
    { CKC_SUPER, MOD_LCTL }
},
```

2. **Add default actions** (if needed):
```c
Action default_actions[][3] = {
    ...
    [KC_HOME] = {{OS_ANDROID, KC_HOME}},
    ...
};
```

3. **Add GUI mask actions** (if needed):
```c
Action gui_mask_actions[][3] = {
    ...
    [KC_SPC] = {{OS_ANDROID, KC_LGUI}},
    ...
};
```

## Known Limitations

1. **No re-enumeration reset**: switching hosts without power loss (KVM, dock) keeps the old wLength counters; `OS_DETECTION_KEYBOARD_RESET` would fix this.

2. **Limited keycodes**: The `gui_mask_actions` array uses keycode as index (0-255), limiting to basic keycodes.

3. **No runtime switching**: User cannot manually override OS detection without code modification.

4. **Hardcoded fallbacks**: Some behaviors like `KC_HOME`/`KC_END` only work on macOS.

5. **Array bounds**: The `sizeof(actions[keycode])` assumes keycode < array size.

## Potential Improvements

1. **Runtime OS switching**: Add keycode to cycle through detected OS
2. **EEPROM storage**: Persist OS selection across power cycles
3. **Dynamic configuration**: VIA integration for user customization
4. **Expanded action mapping**: Use keymap introspection instead of array indexing

## Testing Checklist

- [ ] Linux: Verify Ctrl+C/V with Super key
- [ ] macOS: Verify Cmd+Left/Right for Home/End
- [ ] Windows: Verify Alt+Tab behavior
- [ ] All OS: Verify Space key doesn't apply modifier
- [ ] All OS: Verify Super key deactivation works
- [ ] All OS: Verify Caps Word behavior
