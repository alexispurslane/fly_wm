package main

// #cgo LDFLAGS: -lX11
// #include <X11/Xlib.h>
import "C"

// Go package imports
import (
	"fmt"
)

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	display := C.XOpenDisplay(nil)
	if display == nil {
		panic("Cannot open X display")
	}

	attr := C.XWindowAttributes{}
	start := C.XButtonEvent{}
	start.subwindow = C.None
	event := C.XEvent{} // Custom XEvent struct becouse cgo reads Xlib XEvent struct as a byte array

	// Set up events
	C.XGrabKey(display,
		C.int(C.XKeysymToKeycode(display, C.XStringToKeysym(C.CString("Tab")))),
		C.Mod1Mask, C.XDefaultRootWindow(display), C.True, C.GrabModeAsync, C.GrabModeAsync)

	C.XGrabButton(display, 1, C.Mod1Mask, C.XDefaultRootWindow(display), C.True,
		C.ButtonPressMask|C.ButtonReleaseMask|C.PointerMotionMask, C.GrabModeAsync,
		C.GrabModeAsync, C.None, C.None)
	C.XGrabButton(display, 3, C.Mod1Mask, C.XDefaultRootWindow(display), C.True,
		C.ButtonPressMask|C.ButtonReleaseMask|C.PointerMotionMask, C.GrabModeAsync,
		C.GrabModeAsync, C.None, C.None)
	// Event loop
	for {
		C.XNextEvent(display, &event)

		// Handle window switch keybinding (The type field is a go keyword, so
		// prefix it with an underscore)
		if event._type == C.KeyPress && event.xkey.subwindow != C.None {
			C.XRaiseWindow(display, event.xkey.subwindow)
			fmt.Println("Raising another window")
		} else if event._type == C.ButtonPress && event.xbutton.subwindow != C.None {

			C.XGetWindowAttributes(display, event.xbutton.subwindow, &attr)
			start = event.xbutton

		} else if event._type == C.MotionNotify && start.subwindow != C.None {

			xdiff := event.xbutton.x_root - start.x_root
			ydiff := event.xbutton.y_root - start.y_root

			var moveXDelta int
			var moveYDelta int

			if start.button == 1 {
				moveXDelta = xdiff
			} else {
				moveXDelta = 0
			}

			if start.button == 1 {
				moveYDelta = ydiff
			} else {
				moveYDelta = 0
			}

			var resizeXDelta int
			var resizeYDelta int

			if start.button == 3 {
				resizeXDelta = xdiff
			} else {
				resizeXDelta = 0
			}

			if start.button == 3 {
				resizeYDelta = ydiff
			} else {
				resizeYDelta = 0
			}

			XMoveResizeWindow(display, start.subwindow,
				attr.x+moveXDelta,
				attr.y+moveYDelta,
				max(1, attr.width+resizeXDelta),
				max(1, attr.height+resizeYDelta))
			fmt.Println("Resizing/Moving window: [x: %d, y: %d] and [width: %d, height: %d]", moveXDelta, moveYDelta, resizeXDelta, resizeYDelta)

		} else if event._type == C.ButtonRelease {
			start.subwindow = None
		}
	}
}
