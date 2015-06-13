Fly WM
====================

This is a simple tiling window manager, that aims to be as good-looking and useful as any floating window manager.
It's features include:

* Tiling and tiling setups that are savable
* A central search setup like OS X Yosemite's Spotlight
* Great good looks
* And Activities, similar to KDE

### Disclaimer: It is currently in deep, deep development

Building and Running
--------------------

To build this example window manager, you will need:

* A C++-11 enabled C++ compiler
* [SCons](http://www.scons.org/)
* Xlib headers and libraries
* [google-glog](https://code.google.com/p/google-glog/) library

To run and test it, you will need:

* [Xephyr](http://www.freedesktop.org/wiki/Software/Xephyr/)
* `xinit`
* Random X utilities such as `xclock`, `xeyes`, and `xterm` to play with

On [Arch Linux](http://www.archlinux.org), you can install these with:

    yaourt -S base-devel scons xproto google-glog \
        xorg-server-xephyr xorg-xinit xorg-xclock xorg-xeyes xterm

Consult your own distro's documentation for how to install these.

Once you have all the dependencies, building and running it is as simple as:

    ./build_and_run.sh

This will launch a simple Xephyr session like in the following screenshot:
![Screenshot](basic_wm_screenshot.png)


Usage
-----

Supported keyboard shortcuts:

* **Alt + Left Click**: Move window
* **Alt + Right Click**: Resize window
* **Alt + F4**: Close window
* **Alt + Tab**: Switch window
