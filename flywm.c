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


  char *keys[10] = {
    "q",   // Quit window
    "l",   // Window takes up left half of screen
    "r",   // Window takes up rigt half of screen
    "t",   // Window takes up top half of screen
    "b",   // Window takes up bottom half of screen
    "f",   // Full screen window
    "1",   // Use window's vertical left half
    "2",   // Use window's vertical right half
    "3",   // Use window's horizontal top half
    "4"    // Use window's horizontal bottom half
  };

  // Set up key listeners
  int key = 0;
  for (key = 0; key < 10; key++) {
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym(keys[key])),Mod1Mask,
      root, True, GrabModeAsync, GrabModeAsync);
  }

  // Set up mouse listeners
  XGrabButton(display, 1, Mod1Mask, root, True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);
  XGrabButton(display, 3, Mod1Mask, root, True,
      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
      GrabModeAsync, None, None);
  XGrabButton(display, 1, ShiftMask, root, True,
      ButtonPressMask, GrabModeAsync,
      GrabModeAsync, None, None);

  // Get the top level windows, and check to make sure everything is as we assume it to be
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

  // Add frames to the top level windows
  int i;
  for (i = 0; i < num_top_level_windows; i++) {
    n++;
    windows[n] = top_level_windows[i];
  }

  XFree(top_level_windows);

  start.subwindow = None;

  // Event loop
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
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attrs));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y, // Y
            attrs.width/2, // Width
            attrs.height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("2"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attrs));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x+(attrs.width/2), // X
            attrs.y, // Y
            attrs.width/2, // Width
            attrs.height); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("3"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attrs));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y, // Y
            attrs.width, // Width
            attrs.height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("4"))) {

        XWindowAttributes attrs;
        assert(XGetWindowAttributes(display, event.xkey.subwindow, &attrs));
        move_resize_window(event.xkey.subwindow, attr,
            attrs.x, // X
            attrs.y+(attrs.height/2), // Y
            attrs.width, // Width
            attrs.height/2); // Height
      } else if (event.xkey.keycode == XKeysymToKeycode(display,
            XStringToKeysym("q"))) {

        XDestroyWindow(display, event.xkey.subwindow);
      }
    } else if (event.type == ButtonPress && event.xbutton.state == ShiftMask && event.xbutton.subwindow != None) {
      XRaiseWindow(display, event.xbutton.subwindow);
    } else if (event.type == ButtonPress && event.xbutton.subwindow != None) {
      // If the user starts doing something with the mouse, get the window's attributes
      assert(XGetWindowAttributes(display, event.xbutton.subwindow, &attr));
      start = event.xbutton;
    } else if (event.type == MotionNotify && start.subwindow != None) {
      // When the user starts dragging...
      int x_delta = event.xbutton.x_root - start.x_root; // Get the deltas (x and y)
      int y_delta = event.xbutton.y_root - start.y_root;

      int x_move = start.button == 1 ? x_delta : 0; // If we are left clicking, we are moving the window
      int y_move = start.button == 1 ? y_delta : 0;

      int x_resize = start.button == 3 ? x_delta : 0; // If it is a right click, we are resizing the window
      int y_resize = start.button == 3 ? y_delta : 0;

      move_resize_window(start.subwindow, attr,
          attr.x + x_move, attr.y + y_move,
          max(1, attr.width + x_resize), // Cant make a negative or zero width window
          max(1, attr.height + y_resize));
    } else if (event.type == ButtonRelease) {
      start.subwindow = None;
    }
  }

  return 0;
}

/* Max of two numbers. Whichever is biggest will be returned */
int max(int a, int b) {
  return a > b ? a : b;
}


/* This function moves and resizes the frame window, and it's content window, at the same time.
 * It accesses the content window's index from the frame window, and uses it to get it from the array.
 */
void move_resize_window(Window frame, XWindowAttributes attr,
    int target_x,
    int target_y,
    int target_width,
    int target_height) {

  XMoveResizeWindow(display, frame,
      target_x,
      target_y,
      target_width,
      target_height);
}
