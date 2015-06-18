/* FlyWM is written by Christopher Dumas <christopherdumas@gmail.com> in 2015
 *
 * This software is under the GPL v3 license, and is provided with ABSULUTLY NO WARRENTY
 */

#include <X11/Xlib.h>
#include <assert.h>

#define nil 0x0
#define ever (;;)

int max(int a, int b) {
  return a > b ? a : b;
}

int main () {
  Display *display = XOpenDisplay(nil);
  assert(display);

  XWindowAttributes attr;
  XButtonEvent start;
  XEvent event;

  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("Tab")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Raise focused window
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("q")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Kill focused window
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("l")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Window take up half of the screen on the left
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("r")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Window take up half of the screen on the right
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("t")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Window take up half of the screen on the top
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("b")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Window take up half of the screen on the bottom
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("f")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Window take up whole screen
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("1")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Divide window in half vertically left
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("2")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Divide window in half vertically right
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("3")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Divide window in half horizontally top
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("4")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync); // Divide window in half horizontally bottom



  XGrabButton(display, 1, Mod1Mask, DefaultRootWindow(display), True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);
  XGrabButton(display, 3, Mod1Mask, DefaultRootWindow(display), True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);

  start.subwindow = None;

  for ever {
    XNextEvent(display, &event);

    if (event.type == KeyPress && event.xkey.subwindow != None) {
      if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("Tab"))) {
        XRaiseWindow(display, event.xkey.subwindow);
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("l"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, DefaultRootWindow(display), &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y, // Y
          width/2, // Width
          height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("r"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, DefaultRootWindow(display), &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          width - width/2, // X
          y, // Y
          width/2, // Width
          height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("t"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, DefaultRootWindow(display), &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y, // Y
          width, // Width
          height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("b"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, DefaultRootWindow(display), &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          height - height/2, // Y
          width, // Width
          height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("f"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, DefaultRootWindow(display), &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y, // Y
          width, // Width
          height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("1"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, event.xkey.subwindow, &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y, // Y
          width/2, // Width
          height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("2"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, event.xkey.subwindow, &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x+(width/2), // X
          y, // Y
          width/2, // Width
          height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("3"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, event.xkey.subwindow, &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y, // Y
          width, // Width
          height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("4"))) {
        Window root_return;
        int x,
            y,
            width,
            height,
            border_width,
            depth;

        XGetGeometry(display, event.xkey.subwindow, &root_return, &x, &y, &width,
                      &height, &border_width, &depth);
        XMoveResizeWindow(display, event.xkey.subwindow,
          x, // X
          y+(height/2), // Y
          width, // Width
          height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("q"))) {
        XDestroyWindow(display, event.xkey.subwindow);
      }
    }else if (event.type == ButtonPress && event.xbutton.subwindow != None) {
      XGetWindowAttributes(display, event.xbutton.subwindow, &attr);
      start = event.xbutton;
    } else if (event.type == MotionNotify && start.subwindow != None) {
      int x_delta = event.xbutton.x_root - start.x_root;
      int y_delta = event.xbutton.y_root - start.y_root;

      int x_move = start.button == 1 ? x_delta : 0;
      int y_move = start.button == 1 ? y_delta : 0;

      int x_resize = start.button == 3 ? x_delta : 0;
      int y_resize = start.button == 3 ? y_delta : 0;

      XMoveResizeWindow(display, start.subwindow,
          attr.x + x_move,
          attr.y + y_move,
          max(1, attr.width + x_resize),
          max(1, attr.height + y_resize));
    } else if (event.type == ButtonRelease) {
      start.subwindow = None;
    }
  }

  return 0;
}
