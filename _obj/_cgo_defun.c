
#include "runtime.h"
#include "cgocall.h"

void ·_Cerrno(void*, int32);

void
·_Cfunc_GoString(int8 *p, String s)
{
	s = runtime·gostring((byte*)p);
	FLUSH(&s);
}

void
·_Cfunc_GoStringN(int8 *p, int32 l, String s)
{
	s = runtime·gostringn((byte*)p, l);
	FLUSH(&s);
}

void
·_Cfunc_GoBytes(int8 *p, int32 l, Slice s)
{
	s = runtime·gobytes((byte*)p, l);
	FLUSH(&s);
}

void
·_Cfunc_CString(String s, int8 *p)
{
	p = runtime·cmalloc(s.len+1);
	runtime·memmove((byte*)p, s.str, s.len);
	p[s.len] = 0;
	FLUSH(&p);
}

void
·_Cfunc__CMalloc(uintptr n, int8 *p)
{
	p = runtime·cmalloc(n);
	FLUSH(&p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XDefaultRootWindow
void _cgo_e13b1c1ec8d3_Cfunc_XDefaultRootWindow(void*);

void
·_Cfunc_XDefaultRootWindow(struct{void *y[2];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XDefaultRootWindow, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XGetWindowAttributes
void _cgo_e13b1c1ec8d3_Cfunc_XGetWindowAttributes(void*);

void
·_Cfunc_XGetWindowAttributes(struct{void *y[4];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XGetWindowAttributes, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XGrabButton
void _cgo_e13b1c1ec8d3_Cfunc_XGrabButton(void*);

void
·_Cfunc_XGrabButton(struct{void *y[8];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XGrabButton, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XGrabKey
void _cgo_e13b1c1ec8d3_Cfunc_XGrabKey(void*);

void
·_Cfunc_XGrabKey(struct{void *y[6];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XGrabKey, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XKeysymToKeycode
void _cgo_e13b1c1ec8d3_Cfunc_XKeysymToKeycode(void*);

void
·_Cfunc_XKeysymToKeycode(struct{void *y[3];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XKeysymToKeycode, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XNextEvent
void _cgo_e13b1c1ec8d3_Cfunc_XNextEvent(void*);

void
·_Cfunc_XNextEvent(struct{void *y[3];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XNextEvent, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XOpenDisplay
void _cgo_e13b1c1ec8d3_Cfunc_XOpenDisplay(void*);

void
·_Cfunc_XOpenDisplay(struct{void *y[2];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XOpenDisplay, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XRaiseWindow
void _cgo_e13b1c1ec8d3_Cfunc_XRaiseWindow(void*);

void
·_Cfunc_XRaiseWindow(struct{void *y[3];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XRaiseWindow, &p);
}

#pragma cgo_import_static _cgo_e13b1c1ec8d3_Cfunc_XStringToKeysym
void _cgo_e13b1c1ec8d3_Cfunc_XStringToKeysym(void*);

void
·_Cfunc_XStringToKeysym(struct{void *y[2];}p)
{
	runtime·cgocall(_cgo_e13b1c1ec8d3_Cfunc_XStringToKeysym, &p);
}

