/* FlyWM is written by Christopher Dumas <christopherdumas@gmail.com> in 2015
 *
 * This software is under the GPL v3 license, and is provided with ABSULUTLY NO WARRENTY
 */

#include <X11/Xlib.h>

#define nil 0x0
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main () {
  Display *display = XOpenDisplay(nil);
  if (!display) return 1;

  XWindowAttributes attr;
  XButtonEvent start;
  XEvent event;

  XGrabKey(display, XKeysymToKeyCode(display, XStringToKeysym("Tab")), Mod1Mask,
      DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
  XGrabButton(display, 1, Mod1Mask, DefaultRootWindow(display), True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);
  XGrabButton(display, 3, Mod1Mask, DefaultRootWindow(display), True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);

  start.subwindow = None;

  while (1) {
    XNextEvent(display, &event);

    if (event.type == KeyPress && event.xkey.subwindow != None) {
      XRaiseWindow(display, event.xkey.subwindow);
    } else if (event.type == ButtonPress && event.xbutton.subwindow != None) {
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
          MAX(1, attr.width + x_resize),
          MAX(1, attr.height + y_resize));
    } else if (event.type == ButtonRelease) {
      start.subwindow = None;
    }
  }
}
