/* FlyWM is written by Christopher Dumas <christopherdumas@gmail.com> in 2015
 *
 * This software is under the GPL v3 license,
 * and is provided with ABSULUTLY NO WARRENTY
 *
 * This is the main implementation file, where everything is run.
 */

#include <X11/Xlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define nil 0x0
#define ever (;;)

Window windows[100];
int n = 0;
Display *display;
Window root;

int max(int a, int b);
void add_frame(Window w);
void move_resize_window(Window frame, XWindowAttributes attr,
    int target_x,
    int target_y,
    int target_width,
    int target_height);
int main() {
  display = XOpenDisplay(nil);
  assert(display);
  root = DefaultRootWindow(display);
  assert(root);


  XWindowAttributes attr;
  XButtonEvent start;
  XEvent event;

  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("Tab")),Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("q")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("l")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("r")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("t")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("b")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("f")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("1")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("2")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("3")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("4")), Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);



  XGrabButton(display, 1, Mod1Mask, root, True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);
  XGrabButton(display, 3, Mod1Mask, root, True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);

  Window returned_root, returned_parent;
  Window* top_level_windows;
  int num_top_level_windows;

  assert(XQueryTree(
        display,
        root,
        &returned_root,
        &returned_parent,
        &top_level_windows,
        &num_top_level_windows));
  assert(returned_root == root);

  int i;
  for (i = 0; i < num_top_level_windows; i++) {
    add_frame(top_level_windows[i]);
  }

  XFree(top_level_windows);

  start.subwindow = None;

  for ever {
    XNextEvent(display, &event);

    if (event.type == KeyPress && event.xkey.subwindow != None) {
      XWindowAttributes x_window_attrs;
      assert(XGetWindowAttributes(display, root, &x_window_attrs));
      int root_x = x_window_attrs.x,
          root_y = x_window_attrs.y,
          root_width = x_window_attrs.width,
          root_height = x_window_attrs.height;

      if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("Tab"))) {

        XRaiseWindow(display, event.xkey.subwindow);
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("l"))) {

        move_resize_window(event.xkey.subwindow, attr,
            root_x, // X
            root_y, // Y
            root_width/2, // Width
            root_height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("r"))) {

        move_resize_window(event.xkey.subwindow, attr,
            root_width - root_width/2, // X
            root_y, // Y
            root_width/2, // Width
            root_height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("t"))) {

        move_resize_window(event.xkey.subwindow, attr,
            root_x, // X
            root_y, // Y
            root_width, // Width
            root_height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("b"))) {

        move_resize_window(event.xkey.subwindow, attr,
            root_x, // X
            root_height - root_height/2, // Y
            root_width, // Width
            root_height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("f"))) {

        move_resize_window(event.xkey.subwindow, attr,
            root_x, // X
            root_y, // Y
            root_width, // Width
            root_height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("1"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attr));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y, // Y
            attrs.width/2, // Width
            attrs.height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("2"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attr));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x+(attrs.width/2), // X
            attrs.y, // Y
            attrs.width/2, // Width
            attrs.height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("3"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attr));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y, // Y
            attrs.width, // Width
            attrs.height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("4"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attr));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y+(attrs.height/2), // Y
            attrs.width, // Width
            attrs.height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("q"))) {

        XDestroyWindow(display, event.xkey.subwindow);
      }
    }else if (event.type == ButtonPress && event.xbutton.subwindow != None) {
      assert(XGetWindowAttributes(display, event.xbutton.subwindow, &attr));
      start = event.xbutton;
    } else if (event.type == MotionNotify && start.subwindow != None) {
      int x_delta = event.xbutton.x_root - start.x_root;
      int y_delta = event.xbutton.y_root - start.y_root;

      int x_move = start.button == 1 ? x_delta : 0;
      int y_move = start.button == 1 ? y_delta : 0;

      int x_resize = start.button == 3 ? x_delta : 0;
      int y_resize = start.button == 3 ? y_delta : 0;

      move_resize_window(start.subwindow, attr,
          attr.x + x_move, attr.y + y_move,
          max(1, attr.width + x_resize),
          max(1, attr.height + y_resize));
    } else if (event.type == ButtonRelease) {
      start.subwindow = None;
    }
  }

  return 0;
}

int max(int a, int b) {
  return a > b ? a : b;
}

void add_frame(Window w) {
  const int BORDER_WIDTH = 1;
  const long BORDER_COLOR = 0x6666ff;
  const long BG_COLOR = 0x8888ff;

  XWindowAttributes x_window_attrs;
  assert(XGetWindowAttributes(display, w, &x_window_attrs));

  Window frame = XCreateSimpleWindow(
      display,
      root,
      x_window_attrs.x,
      x_window_attrs.y,
      x_window_attrs.width,
      x_window_attrs.height,
      BORDER_WIDTH,
      BORDER_COLOR,
      BG_COLOR);
  XAddToSaveSet(display, w);
  XReparentWindow(
      display,
      w,
      frame,
      0, 0);
  
  n++;
  windows[n] = w;
  char name[3];
  sprintf(&name, "%d", n);
  XStoreName(display, frame, &name);

  XMapWindow(display, frame);
}

void move_resize_window(Window frame, XWindowAttributes attr,
    int target_x,
    int target_y,
    int target_width,
    int target_height) {

  char *name;
  XFetchName(display, frame, &name);
  Window w = windows[atoi(name)];

  XMoveResizeWindow(display, frame,
      target_x,
      target_y,
      target_width,
      target_height);
  XMoveResizeWindow(display, w,
      attr.x,
      attr.y,
      target_width,
      target_height);
}
