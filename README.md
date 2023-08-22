# SetMica

Applies [Mica backdrop](https://learn.microsoft.com/en-us/windows/apps/design/style/mica) to Win32 application,
and modern light line caption (instead of color fill).

**Important:** The window must use black background (even in light mode) in the affected areas, otherwise it will look ugly.

**Requirements:** Windows 11 22H2 and newer (or build 22543 and newer)

## Usage:

    SetMica64.exe 1 "CLASSNAME" 23 45 67 89

* `1` - which backdrop to use, see below
* `CLASSNAME` - window class name, ask developer or use Spy++ or similar tool
* `23` - number of pixels on the left border, that should use the backdrop
* `45` - same, for right border
* `67` - same, for top border
* `89` - same, for bottom border

To get whole window to apply the backdrop, replace `23 45 67 89` with `-1 -1 -1 -1`.

### Example to use on Total Commander:

    SetMica64.exe 4 TTOTAL_CMD 0 0 113 51

* Only works properly if you set Total Commander (11.00) into Dark mode, and set Dark mode Background color to maximum black.

## Backdrops

0. DWMSBT_AUTO - Default. Let DWM automatically decide the system-drawn backdrop for this window.
1. DWMSBT_NONE - Do not draw any system backdrop.
2. DWMSBT_MAINWINDOW - Draw the backdrop material effect corresponding to a long-lived window.
3. DWMSBT_TRANSIENTWINDOW - Draw the backdrop material effect corresponding to a transient window.
4. DWMSBT_TABBEDWINDOW - Draw the backdrop material effect corresponding to a window with a tabbed title bar.

## Documentation

* https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/apply-mica-win32

# License

Do whatever you want.
