Fly WM
====================

This is a simple tiling window manager, that aims to be as good-looking and useful as any floating window manager.
It's features include:

* Tiling and tiling setups that are savable
* A central search setup like OS X Yosemite's Spotlight
* Flat UI, modern, user-freindly look (Most tiling window mangagers look really ugly.)
* And Activities, similar to KDE

### Disclaimer: It is currently in deep, deep development

Building and Running
--------------------

To build this window manager, you will need:

* Go (Go package)
* XGB (Go package)
* XGB Util (Go package)
* XDG (Go package)
* ANSI (Go package)

To run and test it, you will need:

* [Xephyr](http://www.freedesktop.org/wiki/Software/Xephyr/)
* `xinit`
* Random X utilities such as `xclock`, `xeyes`, and `xterm` to play with

    ./build_and_run.sh

Usage
-----

Supported keyboard shortcuts:

* **Alt + Click**: Resize window
* **Alt + F4**: Close window
* **Alt + Tab**: Switch window
* **Alt + Right Click**: On the home screen, this will open an applications menu
