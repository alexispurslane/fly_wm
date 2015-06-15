extern crate xlib;

fn max<T: std::cmp::ord>(a: T, b: T) -> T {
    if (a < b) {
        b
    } else { a }
}

fn main() {
}
