#![allow(dead_code)]
mod math;
mod subdir;
use subdir::foo;

fn main() {
    println!("val is {}", math::val());
    println!("foo is {}", foo::fee());

}
