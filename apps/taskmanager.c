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
  char *original_name;
  int x, y, width, height;
  GC gc;
} Button;

Window windows[100];
int hidden[100];
Button buttons[100];
Window tooltips[100];

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
      (root_width/2) - 15, 25, 2, 0x666666, 0x222222);

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
        place += add_button(d, window, name.value, place, -2, 170, 25, n);
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
      int i;
      for (i = 0; i < 100; i++) {
        if (tooltips[i]) {
          XUnmapWindow(d, tooltips[i]);
        }
      }
      char *str_i;
      XFetchName(d, event.xbutton.subwindow, &str_i);
      Window selected_window = windows[atoi(str_i)];

      if (selected_window != None) {
        if (hidden[atoi(str_i)]) {
          XMapWindow(d, selected_window);
          XRaiseWindow(d, selected_window);
          hidden[atoi(str_i)] = False;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x222222);
          XSetForeground(d, buttons[atoi(str_i)].gc, 0x666666);
          update_button(d, buttons[atoi(str_i)]);
        } else {
          XUnmapWindow(d, selected_window);
          hidden[atoi(str_i)] = True;
          XSetWindowBackground(d, event.xbutton.subwindow, 0x666666);
          XSetForeground(d, buttons[atoi(str_i)].gc, 0x222222);
          update_button(d, buttons[atoi(str_i)]);
        }
      }
    } else if (event.type == EnterNotify && event.xcrossing.window != None) {
      char *str_i;
      XFetchName(d, event.xcrossing.window, &str_i);

      int i;
      for (i = 0; i < 100; i++) {
        if (tooltips[i]) {
          XUnmapWindow(d, tooltips[i]);
        }
      }
      Button b = buttons[atoi(str_i)];

      Window tooltip = XCreateSimpleWindow(d, DefaultRootWindow(d), b.x+4, root_height-55,
          strlen(b.original_name)*6 + 14, 25, 0, 0x666666, 0x222222);
      GC gc = XCreateGC(d, tooltip, 0, 0);
      XSetBackground(d, gc, 0x222222);
      XSetForeground(d, gc, 0x666666);

      XMapWindow(d, tooltip);
      XDrawString(d, tooltip, gc, 9, 25/2+4, b.original_name, strlen(b.original_name));

      tooltips[atoi(str_i)] = tooltip;
    } else if (event.type == LeaveNotify) {
      int i;
      for (i = 0; i < 100; i++) {
        if (tooltips[i]) {
          XUnmapWindow(d, tooltips[i]);
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

  XSetWindowAttributes x_attributes;
  x_attributes.event_mask = ButtonPressMask | EnterWindowMask | LeaveWindowMask;
  XChangeWindowAttributes(d, button, CWEventMask, &x_attributes);

  GC gc = XCreateGC(d, button, 0, 0);
  XSetBackground(d, gc, 0x222222);
  XSetForeground(d, gc, 0x666666);

  char str_i[3];
  sprintf(str_i, "%d", i);
  XStoreName(d, button, (char *)str_i);

  char *cname = (char *)malloc(100);
  strcpy(cname, name);

  Button b;
  b.window = button;
  b.x = x;
  b.y = y;
  b.width = width;
  b.height = height;
  b.original_name = cname;
  b.gc = gc;

  int changed = 0;

  while ((strlen(name)-2)*8 > width) {
    name[strlen(name)-1] = 0;
    changed = 1;
  }

  XMapWindow(d, button);

  if (changed) strcat(name, "...");
  XDrawString(d, button, gc, 9, (height/2)+4, name, strlen(name));
  XFlush(d);

  b.name = name;
  buttons[i] = b;

  return width;
}

void update_button(Display *d, Button b) {
  XUnmapWindow(d, b.window);
  XMapWindow(d, b.window);

  XDrawString(d, b.window, b.gc, 5, (b.height/2)+5, b.name, strlen(b.name));
}
