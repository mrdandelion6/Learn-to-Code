package java;

public class Notes {

    // welcome to my notes on using java.
    // all sections are listed in the contents() function. you can go to definition.
    // to run a specific section(s) call it in main(). some sections are interactive
    // and contain actual code , while some are just comments.

    public static void main(String[] args) {
        JDK();
    }

    public static void contents() {
        JDK();
        javaCompilation();
        javaOnCommandLine();
    }

    public static void JDK() {
        // JDK stands for java development kit , and it contains everything needed to
        // develop java applications including:

        // 1. JRE (java run time environment) which includes:
        // // - the JVM (java virtual machine)
        // // - core libraries
        // // - support files

        // 2. development tools
        // // - javac (java compiler)
        // // - debugger
        // // - documentaion tools (javadoc)
        // // - other utilities

        // the JDK does not include:
        // 1. build tools like maven or gradle (more on these later)
        // 2. LSP (langauge server protocol)
    }

    public static void javaCompilation() {
        // java is like a mix between compiled and interpreted languages.
        // it uses the JVM (java virtual machine) to run bytecode.

        // WHAT IS BYTECODE ?
        // bytecode is like machine code... low level binary , not assembly though.
        // except unlike binary , bytecode is cross platform. that is the main pont of
        // java: to make a cross platform executable. this means all compiled java
        // source code produces identical bytecode regardless of the machine it was
        // compiled on. when we compile java source code , we get `.class.` files. this
        // is bytecode.

        // but how is this possible? we know that actual machine code cannot be cross
        // platform or even cross device. for example , a C program executable cannot
        // just be run on any computer.. it has to be run on the computer it was
        // compiled on! this works with bytecode because of the JVM! bytecode (those
        // .class files) are not actual executables. it is just very low level binary
        // that the JVM can interpret at runtime.

        // WHAT IS THE JVM ?
        // in exact terms, the JVM is a binary executable usually named `java` on your
        // system. or java.exe on windows. the JVM interprets bytecode as described
        // above. the JVM is part of the JRE which is part of the JDK (see JDK section).
    }

    public static void javaOnCommandLine() {
        // most java developers use tools such as IntelliJ or Eclipse to build their
        // apps. but if you want to work on java in neovim you will need to know how to
        // build things more manually.

        // javac Example.java : compiles the java code
        // java Example : runs the compiled java code
        // jar [options] example.jar *.class : creates a jar file
        // options are c, t, x, u, m, f, v, 0, M, i, C, e, 0, T, P, p, 1, 2, 3, 4, 5, 6,
        // 7, 8, 9
        // c : create new archive
        // t : list table of contents for archive
        // v : generate verbose output

        // jar files are used to package java classes and resources into a single file
        // jar files are similar to zip files
        // jar files are used to distribute java applications or libraries

        // javadoc -d docs Example.java : creates documentation for the java code

    }

}
