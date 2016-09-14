# Fly WM
A exteremely hackable, simple, and modulor window manager and tools, written in C using Xlib. It follows the UNIX phillosophy of:
> Do one thing and do it well.

Fly WM is made of several modules:
* Window manager (based on TinyWM)
* Task Manager (Like a window list)
* Mason (A tiling window manager module, assures that all windows are tiled or marked as floating. Lets Fly WM act like a tiling window manager)
* Exterior Decorator (A module that adds window decorations to Fly WM)
All of these modules exept the window manager are located in the `apps/` directory.
## Dependancies
1. feh
2. Xlib
3. X11
4. GCC
5. Bash
6. XCompmgr
7. xterm
## Key Bindings
* <kbd>Alt</kbd> + <kbd>q</kbd>: Quit window
* <kbd>Alt</kbd> + <kbd>l</kbd>: Window takes up left half of screen
* <kbd>Alt</kbd> + <kbd>r</kbd>: Window takes up rigt half of screen
* <kbd>Alt</kbd> + <kbd>t</kbd>: Window takes up top half of screen
* <kbd>Alt</kbd> + <kbd>b</kbd>: Window takes up bottom half of screen
* <kbd>Alt</kbd> + <kbd>f</kbd>: Full screen window
* <kbd>Alt</kbd> + <kbd>1</kbd>: Use window's vertical left half
* <kbd>Alt</kbd> + <kbd>2</kbd>: Use window's vertical right half
* <kbd>Alt</kbd> + <kbd>3</kbd>: Use window's horizontal top half
* <kbd>Alt</kbd> + <kbd>4</kbd>: Use window's horizontal bottom half
* Alt + Right Drag: Resize window
* Alt + Left Drag: Move window
* Shift + Left Click: Raise Window
