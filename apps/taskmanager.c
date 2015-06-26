/* FlyWM is written by Christopher Dumas <christopherdumas@gmail.com> in 2015
 *
 * This software is under the GPL v3 license,
 * and is provided with ABSULUTLY NO WARRENTY
 *
 * This is the Task Manager module/app.
 */


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil 0x0
#define ever (;;)

typedef struct _Button {
  Window window;
  char *name;
  int x, y, width, height;
  GC gc;
} Button;

Window windows[100];
int hidden[100];
Button buttons[100];

int add_button(Display *d, Window w, char *name,
    int x, int y, int width, int height, int i);
void update_button(Display *d, Button w);
int main() {
  Display *d = XOpenDisplay(nil);

  XWindowAttributes x_window_attrs;
  XGetWindowAttributes(d, DefaultRootWindow(d), &x_window_attrs);
  int root_width = x_window_attrs.width,
      root_height = x_window_attrs.height;
  Window window = XCreateSimpleWindow(d, DefaultRootWindow(d), 0, root_height-30,
      root_width/2, 25, 2, 0x666666, 0x222222);

  XGrabButton(d, 1, 0, window, True,
      ButtonPressMask|ButtonReleaseMask, GrabModeAsync,
      GrabModeAsync, None, None);

  XMapWindow(d, window);

  Window *win_list;
  int win_list_len;

  Window unwanted;
  XQueryTree(
      d,
      DefaultRootWindow(d),
      &unwanted,
      &unwanted,
      &win_list,
      &win_list_len);
  int i, n = 0, place = 0;
  for (i = 0; i < win_list_len; i++) {
    XWindowAttributes attrs;
    XGetWindowAttributes(d, win_list[i], &attrs);

    if (attrs.map_state == IsViewable|IsUnmapped) {
      XTextProperty name;
      int s = XGetWMName(d, win_list[i], &name);


      n++;
      windows[n] = win_list[i];

      if (s != 0) {
        place += add_button(d, window, name.value, place, 0, 170, 25, n);
      } else {
        //place += add_button(d, window, "Unknown", place, 0, 170, 25, n);
      }
    }
  }

  XFlush(d);



  XEvent event;
  for ever {
    XNextEvent(d, &event);

    if (event.type == ButtonPress && event.xbutton.subwindow != None) {
      char *strI;
      XFetchName(d, event.xbutton.subwindow, &strI);
      Window selected_window = windows[atoi(strI)];

      if (selected_window != None) {
        if (hidden[atoi(strI)]) {
          XMapWindow(d, selected_window);
          XRaiseWindow(d, selected_window);
          hidden[atoi(strI)] = False;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x222222);
          XSetForeground(d, buttons[atoi(strI)].gc, 0x666666);
          update_button(d, buttons[atoi(strI)]);
        } else {
          XUnmapWindow(d, selected_window);
          hidden[atoi(strI)] = True;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x666666);
          XSetForeground(d, buttons[atoi(strI)].gc, 0x222222);
          update_button(d, buttons[atoi(strI)]);
        }
      }
    }
  }

  return 0;
}

int add_button(Display *d, Window w, char *name,
    int x, int y, int width, int height, int i) {
  Window button = XCreateSimpleWindow(d, w, x, y,
      width, height, 2, 0x666666, 0x222222);
  GC gc = XCreateGC(d, button, 0, 0);
  XSetBackground(d, gc, 0x222222);
  XSetForeground(d, gc, 0x666666);

  char strI[3];
  sprintf(strI, "%d", i);
  XStoreName(d, button, (char *)strI);

  XMapWindow(d, button);
  XDrawString(d, button, gc, 5, (height/2)+5, name, strlen(name));
  XFlush(d);

  Button b;
  b.window = button;
  b.x = x;
  b.y = y;
  b.width = width;
  b.height = height;
  b.name = name;
  b.gc = gc;

  buttons[i] = b;

  return width;
}

void update_button(Display *d, Button b) {
  XUnmapWindow(d, b.window);
  XMapWindow(d, b.window);
  XDrawString(d, b.window, b.gc, 5, (b.height/2)+5, b.name, strlen(b.name));
}
