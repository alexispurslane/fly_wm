#line 3 "/home/christopherdumas/fly_wm/flywm.go"

 #include <X11/Xlib.h>



// Usual nonsense: if x and y are not equal, the type will be invalid
// (have a negative array count) and an inscrutable error will come
// out of the compiler and hopefully mention "name".
#define __cgo_compile_assert_eq(x, y, name) typedef char name[(x-y)*(x-y)*-2+1];

// Check at compile time that the sizes we use match our expectations.
#define __cgo_size_assert(t, n) __cgo_compile_assert_eq(sizeof(t), n, _cgo_sizeof_##t##_is_not_##n)

__cgo_size_assert(char, 1)
__cgo_size_assert(short, 2)
__cgo_size_assert(int, 4)
typedef long long __cgo_long_long;
__cgo_size_assert(__cgo_long_long, 8)
__cgo_size_assert(float, 4)
__cgo_size_assert(double, 8)

#include <errno.h>
#include <string.h>

void
_cgo_e13b1c1ec8d3_Cfunc_XDefaultRootWindow(void *v)
{
	struct {
		Display* p0;
		Window r;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XDefaultRootWindow((void*)a->p0);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XGetWindowAttributes(void *v)
{
	struct {
		Display* p0;
		Window p1;
		XWindowAttributes* p2;
		int r;
		char __pad28[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XGetWindowAttributes((void*)a->p0, a->p1, (void*)a->p2);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XGrabButton(void *v)
{
	struct {
		Display* p0;
		unsigned int p1;
		unsigned int p2;
		Window p3;
		int p4;
		unsigned int p5;
		int p6;
		int p7;
		Window p8;
		Cursor p9;
		int r;
		char __pad60[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XGrabButton((void*)a->p0, a->p1, a->p2, a->p3, a->p4, a->p5, a->p6, a->p7, a->p8, a->p9);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XGrabKey(void *v)
{
	struct {
		Display* p0;
		int p1;
		unsigned int p2;
		Window p3;
		int p4;
		int p5;
		int p6;
		char __pad36[4];
		int r;
		char __pad44[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XGrabKey((void*)a->p0, a->p1, a->p2, a->p3, a->p4, a->p5, a->p6);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XKeysymToKeycode(void *v)
{
	struct {
		Display* p0;
		KeySym p1;
		KeyCode r;
		char __pad17[7];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XKeysymToKeycode((void*)a->p0, a->p1);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XNextEvent(void *v)
{
	struct {
		Display* p0;
		XEvent* p1;
		int r;
		char __pad20[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XNextEvent((void*)a->p0, (void*)a->p1);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XOpenDisplay(void *v)
{
	struct {
		char* p0;
		const Display* r;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = (__typeof__(a->r)) XOpenDisplay((void*)a->p0);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XRaiseWindow(void *v)
{
	struct {
		Display* p0;
		Window p1;
		int r;
		char __pad20[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XRaiseWindow((void*)a->p0, a->p1);
}

void
_cgo_e13b1c1ec8d3_Cfunc_XStringToKeysym(void *v)
{
	struct {
		char* p0;
		KeySym r;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	a->r = XStringToKeysym((void*)a->p0);
}

