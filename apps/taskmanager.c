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
Window windows[100];
int hidden[100];

void add_button(Display *d, Window w, char *name,
    int x, int y, int width, int height, int i);
void update_window(Display *d, Window w);
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
  char *name, *pname;
  for (i = 0; i < win_list_len; i++) {
    XWindowAttributes attrs;
    XGetWindowAttributes(d, win_list[i], &attrs);

    if (attrs.map_state == IsViewable|IsUnmapped) {
      XClassHint wchint;
      XGetClassHint(d, win_list[i], &wchint);
      pname = name;
      name = wchint.res_name;

      add_button(d, window, name, place, 0, 100, 25, n);
      place += 100;

      n++;
      windows[n] = win_list[i];
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
        XClassHint wchint;
        XGetClassHint(d, selected_window, &wchint);
        char *name = wchint.res_name;

        if (hidden[atoi(strI)]) {
          XMapWindow(d, selected_window);
          XRaiseWindow(d, selected_window);
          hidden[atoi(strI)] = False;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x222222);
          update_window(d, event.xbutton.subwindow);
        } else {
          XUnmapWindow(d, selected_window);
          hidden[atoi(strI)] = True;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x666666);
          update_window(d, event.xbutton.subwindow);
        }
      }
    }
  }

  return 0;
}

void add_button(Display *d, Window w, char *name,
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
  XDrawString(d, button, gc, width/2 - strlen(name)*2, height/2, name, strlen(name));
  XFlush(d);
}

void update_window(Display *d, Window w) {
  XUnmapWindow(d, w);
  XMapWindow(d, w);
}
