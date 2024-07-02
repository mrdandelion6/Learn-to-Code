#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void print_int_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void new_tex(char* text) {
    // creates a tex file and pdf output.tex and output.pdf, overwriting any existing files.
    
    char path[] = "tex/output.tex";

    // opening in append mode
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        fprintf(stderr, "error opening tex file: %s\n", path);
        exit(1);
    }


    fprintf(file, 
        "\\documentclass{article}\n"
        "\\usepackage{amsmath}\n"
        "\\usepackage{hyperref}\n"
        "\\usepackage{enumitem}\n"
        "\\usepackage{geometry}\n"

        "\\title{Terminal Sword: Gameplay Documentation}\n"
        "\\author{mrdandelion6}\n"
        "\\date{April 2024}\n"
        "\n"
        "\\hypersetup{\n"
        "    colorlinks=true,\n"
        "    linkcolor=blue,\n"
        "    urlcolor=blue,\n"
        "}\n"
        "\n"
        "%% ===\n"
        "\\newenvironment{mypar}{%%\n"
        "    \\setlength{\\parskip}{1em}\n"
        "    \\parindent=0pt%%\n"
        "}{%%\n"
        "    \\par%%\n"
        "}\n"
        "\n"
        "\\makeatletter\n"
        "\\renewcommand\\section{\\@startsection {section}{1}{\\z@}%%\n"
        "                                   {-5ex \\@plus -1ex \\@minus -.2ex}%% above\n"
        "                                   {1ex \\@plus .2ex}%% below\n"
        "                                   {\\normalfont\\Large\\bfseries}}\n"
        "\\makeatother\n"
        "\n"
        "\\newenvironment{cindent}[1]{%%\n"
        "    \\par%%%%\n"
        "    \\setlength{\\leftskip}{#1}%% Set the left indentation\n"
        "    \\noindent%% No paragraph indentation\n"
        "    \\ignorespaces%% Ignore spaces after \\begin{customindent}\n"
        "}{%%\n"
        "    \\par%% End the paragraph\n"
        "}\n"
        "\n"
        "%% ===\n"
        "\n"
        "\\def\\marg{3cm}\n"
        "\\geometry{\n"
        "    left=\\marg,\n"
        "    right=\\marg,\n"
        "    top=\\marg,\n"
        "    bottom=\\marg,\n"
        "}\n"
        "begin{document}\n\n"
        "%%s\n"
        "\\end{document}", 
        text);
        
    fclose(file);
    system("cd tex; pdflatex output.tex; cd ..; mv tex/output.pdf .");
}

void add_tex_output(char* text) {
    // appends text to the end of the tex file, then compiles the tex file into a pdf

    char path[] = "tex/output.tex";

    // opening in append mode
    FILE* file = fopen(path, "r+");
    if (file == NULL) {
        fprintf(stderr, "error opening tex file: %%s\n", path);
        exit(1);
    }

    // first we need to remove the "/end document" line
    fseek(file, -1, SEEK_END);
    int offset = -1;
    while (fgetc(file) != '\n') {
        offset--;
        fseek(file, offset, SEEK_END);
    }
    // now offset points to the last character of the second line from the end
    // so offset + 1 will be the first character of the last line

    // printf("found offset: %%d\n", offset);

    fseek(file, offset + 1, SEEK_END);
    fprintf(file, "%%s\n\\end{document}", text);
    fclose(file);

    // compile tex into pdf
    system("cd tex; pdflatex output.tex; cd ..; mv tex/output.pdf .");
}
