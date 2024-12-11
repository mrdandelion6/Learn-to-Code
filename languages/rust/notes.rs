#![allow(dead_code)]

// WELCOME TO MY RUST NOTES
// hi, welcome to my rust notes.
// in these notes you will learn how to write rust code.
// we will start from the basics and work our way to more advanced topics.
// these notes assume you have a decent grasp over programming in general and are familiar with other languages already.
// it will aid you greatly if you are familiar with C/C++, but do not worry if you aren't.
// if you are fairly new to programming, you will likely want to use these notes in addition to other resources to fill in any gaps.

fn main() {
    // RUN
    compiling_rust();
}

fn topics() {
    // INTRODUCTION
    what_is_rust();
    compiling_rust();
    using_cargo();

    // BASIC SYNTAX
    variables();
    types();
    functions();
    control_flows();

    // MODULES AND PROJECT STRUCTURE
    module_system();
    visibility_rules();
    packages_and_crates();
    external_dependencies();

    // OWNERSHIP AND BORROWING
    ownership_rules();
    move_semantics();
    references_and_borrowing();
    borrow_checker();

    // COMPOUND TYPES
    structs_and_methods();
    enums();
    pattern_matching();
    tuples();
    arrays();

    // ERROR HANDLING
    result_and_option();
    question_mark_operator();
    custom_error_types();
    propagating_errors();

    // TRAITS AND GENERICS
    traits();
    generic_types();
    generic_functions();
    trait_bounds();
    associated_types();
    default_implementations();

    // MEMORY MANAGEMENT
    stack();
    heap();
    smart_pointers();
    interior_mutability();
    drop_trait();

    // CONCURRENCY
    threads();
    message_passing();
    shared_state();
    send_and_sync();
    atomic_types();

    // ADVANCED TOPICS
    unsafe_rust();
    ffi_bindings();
    c_bindings();
    closures();
    zero_cost_abstraction();
    macros();
}

fn what_is_rust() {
    // rust is a systems programming language developed by mozilla research.
    // it is designed to be safe, concurrent, and practical.
    // what makes rust special is its core focus on MEMORY SAFETY and THREAD SAFETY 
    // without sacrificing performance.
    // rust achieves this through its unique "OWNERSHIP" system and compile-time checking.
    // these prevent common programming errors like null pointer dereferencing and data races at compile time.

    // rust is a compiled language--it compiles directly to machine code, making it as fast as C and C++. 
    // the official compiler is called rustc.

    // here are some unique features of rust:
        // 1. ownership system : 
            // every value has a single "owner" variable.
            // when the owner goes out of scope, the value is automatically deallocated.
            // this prevents mem leaks and double-free errors.
        // 2. borrowing and references :
            // you can temporarily borrow values without taking ownership.
            // strict rules prevent data races.
        // 3. zero-cost abstractions :
            // rust provides high-level features that compile down to efficient low-level code.
            // this is a key idea--it offers high level at the cost of no runtime overhead.
        // 4. pattern matching :
            // rust has powerful pattern matching capabilities that making handling complex data structures more manageable.

    // rust is particularly good for :
        // systems programming - operating systems or embedded systems
        // performance critical applications
        // concurrent/parallel programming
        // applications requiring high reliability
        // web-assembly development
}

fn compiling_rust() {
    // to get started with coding and compiling rust, we will need three things :
        // 1. rustc - the rust compiler
        // 2. cargo - rust's package manager and build tool
        // 3. rustup - for managing rust versions

    // windows :
    // on windows you can go here https://rustup.rs
    // you'll also need microsoft visual studio C++ build tools

    // macOS/linux :
    // run the command : curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
    // this installs everything we need. restart terminal once you are done.

    // COMPILING RUST
    // now we will move on to compiling rust.
    // there are two different ways:
        // 1. direct compilation with rustc
        // 2. using cargo

    // DIRECTLY COMPILING WITH RUSTC
    // for a single file, say this file notes.rs, run the following:
    // rustc notes.rc
    // ./notes

    // try it out yourself and this should be printed after you put compiling_rust() in main()
    println!("you compiled and ran notes.rs !");
    // rust is just like C and C++ in that it needs a main() function as an entry point into the program.
    // for these notes, whenever you want to run the output for a specific topic, just replace the function being called (under // RUN) in main() with the one u want

    // for using cargo, see the next section.
}

fn using_cargo() {
    // cargo is rusts official package manager and build system.
    // think of npm for js or pip for python, but it does more.

    // here's what cargo does :
        // 1. package management
        //      - manages project dependencies
        //      - downloads and compiles the dependencies automatically
        //      - ensures you get the right versions of everything
        // 2. build system
        //      - compiles your project and all its deps
        //      - handles different build configs (build vs release)
        //      - makes sure everything is built in the proper order
        // 3. project organization
        //      - creates a standard project structure
        //      - manages multiple source files 
        //      - handles configuration through Cargo.toml
        //      - makes it easy to share your code
    
    // cargo's main advantage is that it solves the "it works on my machine" problem.
    // when you share a rust project, cargo ensures that everyone who builds it gets the same result because it:
        // locks dependency versions
        //  uses the same build settings
        // manages everything in a consistent way
    
    // USING CARGO
    // to begin with, we must make a new project with cargo. run the following command:
        // cargo new my_app
    // the above is for a binary (executable) project
    
    // if you would like to just make a library project that gets linked to other things, you can run:
        // cargo new my_library --lib
    // for now we will be making a binary project.

    // we get the following project structure:
    /* 
    my_app/
    ├── Cargo.toml
    └── src
        └── main.rs
    */

    // where main.rs just has:
    fn main() {
        println!("Hello, world!");
    }

    // and Cargo.toml will have something like:
    /* 
    [package]
    name = "my_app"
    version = "0.1.0"
    edition = "2021"

    [dependencies]
    */

    // note that [package] is the heading for project itself.
    // your project is considered a package. name specifies the name of your package.
    // version indicates the current version of your package, starting with "0.1.0".
    // edition specifies which edition of rust your project uses (2021).
    // and [dependencies] is the heading for the dependencies that your package uses. starts empty.

    
} 

fn variables() {
    todo!("Will implement variables section");
}

fn types() {
    todo!("Will implement types section");
}

fn functions() {
    todo!("Will implement functions section");
}

fn control_flows() {
    todo!("Will implement control flows section");
}

fn module_system() {
    todo!("Will implement module system section");
}

fn visibility_rules() {
    todo!("Will implement visibility rules section");
}

fn packages_and_crates() {
    todo!("Will implement packages and crates section");
}

fn external_dependencies() {
    todo!("Will implement external dependencies section");
}

fn ownership_rules() {
    todo!("Will implement ownership rules section");
}

fn move_semantics() {
    todo!("Will implement move semantics section");
}

fn references_and_borrowing() {
    todo!("Will implement references and borrowing section");
}

fn borrow_checker() {
    todo!("Will implement borrow checker section");
}

fn structs_and_methods() {
    todo!("Will implement structs and methods section");
}

fn enums() {
    todo!("Will implement enums section");
}

fn pattern_matching() {
    todo!("Will implement pattern matching section");
}

fn tuples() {
    todo!("Will implement tuples section");
}

fn arrays() {
    todo!("Will implement arrays section");
}

fn result_and_option() {
    todo!("Will implement result and option section");
}

fn question_mark_operator() {
    todo!("Will implement question mark operator section");
}

fn custom_error_types() {
    todo!("Will implement custom error types section");
}

fn propagating_errors() {
    todo!("Will implement propagating errors section");
}

fn traits() {
    todo!("Will implement traits section");
}

fn generic_types() {
    todo!("Will implement generic types section");
}

fn generic_functions() {
    todo!("Will implement generic functions section");
}

fn trait_bounds() {
    todo!("Will implement trait bounds section");
}

fn associated_types() {
    todo!("Will implement associated types section");
}

fn default_implementations() {
    todo!("Will implement default implementations section");
}

fn stack() {
    todo!("Will implement stack section");
}

fn heap() {
    todo!("Will implement heap section");
}

fn smart_pointers() {
    todo!("Will implement smart pointers section");
}

fn interior_mutability() {
    todo!("Will implement interior mutability section");
}

fn drop_trait() {
    todo!("Will implement drop trait section");
}

fn threads() {
    todo!("Will implement threads section");
}

fn message_passing() {
    todo!("Will implement message passing section");
}

fn shared_state() {
    todo!("Will implement shared state section");
}

fn send_and_sync() {
    todo!("Will implement send and sync section");
}

fn atomic_types() {
    todo!("Will implement atomic types section");
}

fn unsafe_rust() {
    todo!("Will implement unsafe rust section");
}

fn ffi_bindings() {
    todo!("Will implement ffi bindings section");
}

fn c_bindings() {
    todo!("Will implement C bindings section");
}

fn closures() {
    todo!("Will implement closures section");
}

fn zero_cost_abstraction() {
    todo!("Will implement zero cost abstraction section");
}

fn macros() {
    todo!("Will implement macros section");
}