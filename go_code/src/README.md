# Fly WM
A exteremely hackable, simple, and modulor window manager and tools, written in C using Xlib. It follows the UNIX phillosophy of:

> Do one thing and do it well

Fly WM is made of several modules:
* Window manager (based on TinyWM)
* Task Master (Sort of like a panel in XFCE)
* Task Manager (Like a window list bar)
* Mason (A tiling window manager module, assures that all windows are tiled or marked as floating. Lets Fly WM act like a tiling window manager)
* Settings Manager
* Exterior Decorator (A module that adds window decorations to Fly WM)

All of these modules exept the window manager are located in the `apps/` directory.

## Dependancies
1. feh
2. Xlib
3. Xorg
4. GCC
5. Bash

## Docs
The commands are as follows:
* <kbd>Alt</kbd> + <kbd>Tab</kbd>: Raise window
* <kbd>Alt</kbd> + <kbd>q</kbd>: Quit window
* <kbd>Alt</kbd> + <kbd>l</kbd>: Window takes up left half of screen
* <kbd>Alt</kbd> + <kbd>r</kbd>: Window takes up rigt half of screen
* <kbd>Alt</kbd> + <kbd>t</kbd>: Window takes up top half of screen
* <kbd>Alt</kbd> + <kbd>b</kbd>: Window takes up bottom half of scre
* <kbd>Alt</kbd> + <kbd>f</kbd>: Full screen window
* <kbd>Alt</kbd> + <kbd>1</kbd>: Use window's vertical left half
* <kbd>Alt</kbd> + <kbd>2</kbd>: Use window's vertical right half
* <kbd>Alt</kbd> + <kbd>3</kbd>: Use window's horizontal top half
* <kbd>Alt</kbd> + <kbd>4</kbd>: Use window's horizontal bottom half
* <kbd>Alt</kbd> + <kbd>Click</kbd>: Move clicked window
* <kbd>Alt</kbd> + <kbd>Right-Click</kbd>: Resize clicked window
