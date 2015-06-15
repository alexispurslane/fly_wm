// Created by cgo - DO NOT EDIT

//line /home/christopherdumas/fly_wm/flywm.go:1
package main
//line /home/christopherdumas/fly_wm/flywm.go:8

//line /home/christopherdumas/fly_wm/flywm.go:7
func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
//line /home/christopherdumas/fly_wm/flywm.go:16

//line /home/christopherdumas/fly_wm/flywm.go:15
func main() {
	display := _Cfunc_XOpenDisplay(nil)
	if display == nil {
		panic("Cannot open X display")
	}
//line /home/christopherdumas/fly_wm/flywm.go:22

//line /home/christopherdumas/fly_wm/flywm.go:21
	attr := _Ctype_struct___0{}
							start := _Ctype_struct___4{}
							start.subwindow = _Cconst_None
							event := _Ctype_XEvent{}
//line /home/christopherdumas/fly_wm/flywm.go:28

//line /home/christopherdumas/fly_wm/flywm.go:27
	_Cfunc_XGrabKey(display,
		_Ctype_int(_Cfunc_XKeysymToKeycode(display, _Cfunc_XStringToKeysym(_Cfunc_CString("Enter")))),
								_Cconst_Mod1Mask, _Cfunc_XDefaultRootWindow(display), _Cconst_True, _Cconst_GrabModeAsync, _Cconst_GrabModeAsync)
//line /home/christopherdumas/fly_wm/flywm.go:32

//line /home/christopherdumas/fly_wm/flywm.go:31
	_Cfunc_XGrabButton(display, 1, _Cconst_Mod1Mask, _Cfunc_XDefaultRootWindow(display), _Cconst_True,
		_Cconst_ButtonPressMask|_Cconst_ButtonReleaseMask|_Cconst_PointerMotionMask, _Cconst_GrabModeAsync,
		_Cconst_GrabModeAsync, _Cconst_None, _Cconst_None)
	_Cfunc_XGrabButton(display, 3, _Cconst_Mod1Mask, _Cfunc_XDefaultRootWindow(display), _Cconst_True,
		_Cconst_ButtonPressMask|_Cconst_ButtonReleaseMask|_Cconst_PointerMotionMask, _Cconst_GrabModeAsync,
		_Cconst_GrabModeAsync, _Cconst_None, _Cconst_None)
//line /home/christopherdumas/fly_wm/flywm.go:39

//line /home/christopherdumas/fly_wm/flywm.go:38
	for {
								_Cfunc_XNextEvent(display, &event)
//line /home/christopherdumas/fly_wm/flywm.go:44

//line /home/christopherdumas/fly_wm/flywm.go:43
		if event._type == _Cconst_KeyPress && event.xkey.subwindow != _Cconst_None {
			_Cfunc_XRaiseWindow(display, event.xkey.subwindow)
		} else if event._type == _Cconst_ButtonPress && event.xbutton.subwindow != _Cconst_None {
//line /home/christopherdumas/fly_wm/flywm.go:48

//line /home/christopherdumas/fly_wm/flywm.go:47
			_Cfunc_XGetWindowAttributes(display, event.xbutton.subwindow, &attr)
									start = event.xbutton
//line /home/christopherdumas/fly_wm/flywm.go:51

//line /home/christopherdumas/fly_wm/flywm.go:50
		} else if event._type == _Cconst_MotionNotify && start.subwindow != _Cconst_None {
//line /home/christopherdumas/fly_wm/flywm.go:53

//line /home/christopherdumas/fly_wm/flywm.go:52
			xdiff := event.xbutton.x_root - start.x_root
									ydiff := event.xbutton.y_root - start.y_root
//line /home/christopherdumas/fly_wm/flywm.go:56

//line /home/christopherdumas/fly_wm/flywm.go:55
			var moveXDelta int
									var moveYDelta int
//line /home/christopherdumas/fly_wm/flywm.go:59

//line /home/christopherdumas/fly_wm/flywm.go:58
			if start.button == 1 {
				moveXDelta = xdiff
			} else {
				moveXDelta = 0
			}
//line /home/christopherdumas/fly_wm/flywm.go:65

//line /home/christopherdumas/fly_wm/flywm.go:64
			if start.button == 1 {
				moveYDelta = ydiff
			} else {
				moveYDelta = 0
			}
//line /home/christopherdumas/fly_wm/flywm.go:71

//line /home/christopherdumas/fly_wm/flywm.go:70
			var resizeXDelta int
									var resizeYDelta int
//line /home/christopherdumas/fly_wm/flywm.go:74

//line /home/christopherdumas/fly_wm/flywm.go:73
			if start.button == 3 {
				resizeXDelta = xdiff
			} else {
				resizeXDelta = 0
			}
//line /home/christopherdumas/fly_wm/flywm.go:80

//line /home/christopherdumas/fly_wm/flywm.go:79
			if start.button == 3 {
				resizeYDelta = ydiff
			} else {
				resizeYDelta = 0
			}
//line /home/christopherdumas/fly_wm/flywm.go:86

//line /home/christopherdumas/fly_wm/flywm.go:85
			XMoveResizeWindow(display, start.subwindow,
				attr.x+moveXDelta,
				attr.y+moveYDelta,
				max(1, attr.width+resizeXDelta),
				max(1, attr.height+resizeYDelta))
//line /home/christopherdumas/fly_wm/flywm.go:92

//line /home/christopherdumas/fly_wm/flywm.go:91
		} else if event._type == _Cconst_ButtonRelease {
			start.subwindow = None
		}
	}
}
