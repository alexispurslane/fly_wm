#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <ctime>

int main (int argc, char *argv[])
{
  Display                 *display;
  Visual                  *visual;
  int                     depth;
  int                     text_x;
  int                     text_y;
  XSetWindowAttributes    frame_attributes;
  Window                  frame_window;
  XFontStruct             *fontinfo;
  XGCValues               gr_values;
  GC                      graphical_context;
  XKeyEvent               event;
  char                    contents[80] = "                                                                               ";
  time_t                  rawtime;
  struct tm               *timeinfo;
  int                     contents_length = strlen(contents);

  display = XOpenDisplay(NULL);
  visual = DefaultVisual(display, 0);
  depth  = DefaultDepth(display, 0);

  frame_attributes.background_pixel = XWhitePixel(display, 0);
  /* create the application window */
  frame_window = XCreateWindow(display, XRootWindow(display, 0),
      0, 0, 500, 50, 5, depth,
      InputOutput, visual, CWBackPixel,
      &frame_attributes);
  XStoreName(display, frame_window, "Fly Taskbar");
  XSelectInput(display, frame_window, ExposureMask | StructureNotifyMask);

  fontinfo = XLoadQueryFont(display, "10x20");
  gr_values.font = fontinfo->fid;
  gr_values.foreground = XBlackPixel(display, 0);
  graphical_context = XCreateGC(display, frame_window,
      GCFont+GCForeground, &gr_values);
  XMapWindow(display, frame_window);

  while ( 1 ) {
    XNextEvent(display, (XEvent *)&event);
    switch ( event.type ) {
      case Expose:
        {
          XClearWindow(display, frame_window);
          // Upkeep of interface usefulness.
          Window returned_root, returned_parent;
          Window* top_level_windows;
          unsigned int nwin = 0;
          XQueryTree(
              display,
              XDefaultRootWindow(display),
              &returned_root,
              &returned_parent,
              &top_level_windows,
              &nwin);

          time(&rawtime);
          timeinfo = localtime(&rawtime);
          strftime(contents, 80, "%a %d %b, %T %p", timeinfo);

          sprintf(contents, "%s [%d]", contents, nwin);


          XWindowAttributes window_attributes;
          int font_direction, font_ascent, font_descent;
          XCharStruct text_structure;
          XTextExtents(fontinfo, contents, contents_length,
              &font_direction, &font_ascent, &font_descent,
              &text_structure);
          XGetWindowAttributes(display, frame_window, &window_attributes);
          text_x = (window_attributes.width - text_structure.width) + 5;
          text_y = (window_attributes.height -
              (text_structure.ascent+text_structure.descent))/2;
          XDrawString(display, frame_window, graphical_context,
              text_x, text_y, contents, contents_length);
          break;
        }
      default:
        break;
    }
  }
  return 0;
}


