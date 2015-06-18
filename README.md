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
6. libxt-dev or libxt or libxt-devel (depending on your OS. Also known as XT Intrinsics)
