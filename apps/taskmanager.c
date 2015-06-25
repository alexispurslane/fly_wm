/* FlyWM is written by Christopher Dumas <christopherdumas@gmail.com> in 2015
 *
 * This software is under the GPL v3 license,
 * and is provided with ABSULUTLY NO WARRENTY
 *
 * This is the Task Manager module/app.
 */


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil 0x0
#define ever (;;)
Window windows[100];

void add_button(Display *d, Window w, GC gc, char *name,
    int x, int y, int width, int height, int i);
int main() {
  Display *d = XOpenDisplay(nil);

  Window window = XCreateSimpleWindow(d, DefaultRootWindow(d), 0, 0,
      100, 300, 2, 0x666666, 0x222222);
  GC gc = XCreateGC(d, window, 0, 0);
  XSetBackground(d, gc, 0x222222);
  XSetForeground(d, gc, 0x666666);

  XGrabButton(d, 1, 0, window, True,
      ButtonPressMask|ButtonReleaseMask, GrabModeAsync,
      GrabModeAsync, None, None);

  XMapWindow(d, window);


  XEvent event;
  for ever {
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

    int i, n = 0;
    for (i = 0; i < win_list_len; i++) {
      XWindowAttributes attrs;
      XGetWindowAttributes(d, win_list[i], &attrs);

      if (attrs.map_state == IsViewable) {
        XClassHint wchint;
        XGetClassHint(d, win_list[i], &wchint);
        char *name = wchint.res_name;

        add_button(d, window, gc, name, -2, n*50, 100, 50, n);
        n++;
        fprintf(stderr, "%d: %s\n", n, name);
        windows[n] = win_list[i];
      }
    }

    XFlush(d);

    XNextEvent(d, &event);

    if (event.type == ButtonPress && event.xbutton.subwindow != None) {
      char *strI;
      XFetchName(d, event.xbutton.subwindow, &strI);
      fprintf(stderr, "%s\n", strI);
      Window selected_window = windows[atoi(strI)];

      XClassHint wchint;
      XGetClassHint(d, selected_window, &wchint);
      char *name = wchint.res_name;
      fprintf(stderr, "%s\n", name);

      XRaiseWindow(d, selected_window);
    }
  }

  return 0;
}

void add_button(Display *d, Window w, GC gc, char *name,
    int x, int y, int width, int height, int i) {
  Window button = XCreateSimpleWindow(d, w, x, y,
      width, height, 2, 0x666666, 0x222222);
  char strI[3];
  XStoreName(d, button, (char *)strI);

  XDrawString(d, button, gc, x+2, y+2, name, strlen(name));
  XMapWindow(d, button);
}
