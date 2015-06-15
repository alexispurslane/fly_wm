// Created by cgo - DO NOT EDIT

package main

import "unsafe"

import "syscall"

import _ "runtime/cgo"

type _ unsafe.Pointer

func _Cerrno(dst *error, x int32) { *dst = syscall.Errno(x) }
type _Ctype_Colormap _Ctype_XID

type _Ctype_Cursor _Ctype_XID

type _Ctype_Depth _Ctype_struct___3

type _Ctype_Display _Ctype_struct__XDisplay

type _Ctype_GC *_Ctype_struct__XGC

type _Ctype_KeyCode _Ctype_unsignedchar

type _Ctype_KeySym _Ctype_XID

type _Ctype_Screen _Ctype_struct___2

type _Ctype_Time _Ctype_ulong

type _Ctype_Visual _Ctype_struct___1

type _Ctype_VisualID _Ctype_ulong

type _Ctype_Window _Ctype_XID

type _Ctype_XButtonEvent _Ctype_struct___4

type _Ctype_XEvent [192]byte

type _Ctype_XExtData _Ctype_struct__XExtData

type _Ctype_XID _Ctype_ulong

type _Ctype_XPointer *_Ctype_char

type _Ctype_XWindowAttributes _Ctype_struct___0

type _Ctype_char int8

type _Ctype_int int32

type _Ctype_long int64

type _Ctype_struct__XDisplay struct{}

type _Ctype_struct__XExtData struct {
//line :1
	number		_Ctype_int
//line :1
	_		[4]byte
//line :1
	next		*_Ctype_struct__XExtData
//line :1
	free_private	*[0]byte
//line :1
	private_data	_Ctype_XPointer
//line :1
}

type _Ctype_struct__XGC struct{}

type _Ctype_struct___0 struct {
//line :1
	x			_Ctype_int
//line :1
	y			_Ctype_int
//line :1
	width			_Ctype_int
//line :1
	height			_Ctype_int
//line :1
	border_width		_Ctype_int
//line :1
	depth			_Ctype_int
//line :1
	visual			*_Ctype_struct___1
//line :1
	root			_Ctype_Window
//line :1
	class			_Ctype_int
//line :1
	bit_gravity		_Ctype_int
//line :1
	win_gravity		_Ctype_int
//line :1
	backing_store		_Ctype_int
//line :1
	backing_planes		_Ctype_ulong
//line :1
	backing_pixel		_Ctype_ulong
//line :1
	save_under		_Ctype_int
//line :1
	_			[4]byte
//line :1
	colormap		_Ctype_Colormap
//line :1
	map_installed		_Ctype_int
//line :1
	map_state		_Ctype_int
//line :1
	all_event_masks		_Ctype_long
//line :1
	your_event_mask		_Ctype_long
//line :1
	do_not_propagate_mask	_Ctype_long
//line :1
	override_redirect	_Ctype_int
//line :1
	_			[4]byte
//line :1
	screen			*_Ctype_struct___2
//line :1
}

type _Ctype_struct___1 struct {
//line :1
	ext_data	*_Ctype_struct__XExtData
//line :1
	visualid	_Ctype_VisualID
//line :1
	class		_Ctype_int
//line :1
	_		[4]byte
//line :1
	red_mask	_Ctype_ulong
//line :1
	green_mask	_Ctype_ulong
//line :1
	blue_mask	_Ctype_ulong
//line :1
	bits_per_rgb	_Ctype_int
//line :1
	map_entries	_Ctype_int
//line :1
}

type _Ctype_struct___2 struct {
//line :1
	ext_data	*_Ctype_struct__XExtData
//line :1
	display		*_Ctype_struct__XDisplay
//line :1
	root		_Ctype_Window
//line :1
	width		_Ctype_int
//line :1
	height		_Ctype_int
//line :1
	mwidth		_Ctype_int
//line :1
	mheight		_Ctype_int
//line :1
	ndepths		_Ctype_int
//line :1
	_		[4]byte
//line :1
	depths		*_Ctype_struct___3
//line :1
	root_depth	_Ctype_int
//line :1
	_		[4]byte
//line :1
	root_visual	*_Ctype_struct___1
//line :1
	default_gc	_Ctype_GC
//line :1
	cmap		_Ctype_Colormap
//line :1
	white_pixel	_Ctype_ulong
//line :1
	black_pixel	_Ctype_ulong
//line :1
	max_maps	_Ctype_int
//line :1
	min_maps	_Ctype_int
//line :1
	backing_store	_Ctype_int
//line :1
	save_unders	_Ctype_int
//line :1
	root_input_mask	_Ctype_long
//line :1
}

type _Ctype_struct___3 struct {
//line :1
	depth		_Ctype_int
//line :1
	nvisuals	_Ctype_int
//line :1
	visuals		*_Ctype_struct___1
//line :1
}

type _Ctype_struct___4 struct {
//line :1
	_type		_Ctype_int
//line :1
	_		[4]byte
//line :1
	serial		_Ctype_ulong
//line :1
	send_event	_Ctype_int
//line :1
	_		[4]byte
//line :1
	display		*_Ctype_struct__XDisplay
//line :1
	window		_Ctype_Window
//line :1
	root		_Ctype_Window
//line :1
	subwindow	_Ctype_Window
//line :1
	time		_Ctype_Time
//line :1
	x		_Ctype_int
//line :1
	y		_Ctype_int
//line :1
	x_root		_Ctype_int
//line :1
	y_root		_Ctype_int
//line :1
	state		_Ctype_uint
//line :1
	button		_Ctype_uint
//line :1
	same_screen	_Ctype_int
//line :1
	_		[4]byte
//line :1
}

type _Ctype_uint uint32

type _Ctype_ulong uint64

type _Ctype_union__XEvent [192]byte

type _Ctype_unsignedchar uint8

type _Ctype_void [0]byte
const _Cconst_ButtonPress = 0x4
const _Cconst_ButtonPressMask = 0x4
const _Cconst_ButtonRelease = 0x5
const _Cconst_ButtonReleaseMask = 0x8
const _Cconst_GrabModeAsync = 0x1
const _Cconst_KeyPress = 0x2
const _Cconst_Mod1Mask = 0x8
const _Cconst_MotionNotify = 0x6
const _Cconst_None = 0x0
const _Cconst_PointerMotionMask = 0x40
const _Cconst_True = 0x1

func _Cfunc_CString(string) *_Ctype_char
func _Cfunc_XDefaultRootWindow(*_Ctype_struct__XDisplay) _Ctype_Window
func _Cfunc_XGetWindowAttributes(*_Ctype_struct__XDisplay, _Ctype_Window, *_Ctype_struct___0) _Ctype_int
func _Cfunc_XGrabButton(*_Ctype_struct__XDisplay, _Ctype_uint, _Ctype_uint, _Ctype_Window, _Ctype_int, _Ctype_uint, _Ctype_int, _Ctype_int, _Ctype_Window, _Ctype_Cursor) _Ctype_int
func _Cfunc_XGrabKey(*_Ctype_struct__XDisplay, _Ctype_int, _Ctype_uint, _Ctype_Window, _Ctype_int, _Ctype_int, _Ctype_int) _Ctype_int
func _Cfunc_XKeysymToKeycode(*_Ctype_struct__XDisplay, _Ctype_KeySym) _Ctype_KeyCode
func _Cfunc_XNextEvent(*_Ctype_struct__XDisplay, *_Ctype_XEvent) _Ctype_int
func _Cfunc_XOpenDisplay(*_Ctype_char) *_Ctype_struct__XDisplay
func _Cfunc_XRaiseWindow(*_Ctype_struct__XDisplay, _Ctype_Window) _Ctype_int
func _Cfunc_XStringToKeysym(*_Ctype_char) _Ctype_KeySym
