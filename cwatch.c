/** includes **/
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int e_cur;
static int e_tot;

char c;

static char logdir[128];

int e_logdir() {
    FILE *fpipe;
    char buf[128];
    char cmd[] = "portageq envvar EMERGE_LOG_DIR";
    
    if (0 == (fpipe = (FILE*)popen(cmd, "r")))
    {
        perror ("popen() failed.");
        exit (EXIT_FAILURE);
    }

    fread(&buf, sizeof buf, 128, fpipe);
    
    /*
    if (  &buf empty string  )
        logdir = /var/log/portage/
    else
        logdir = &buf
    */
    pclose(fpipe);

    return EXIT_SUCCESS;
}

void read_char() {
    if ((c = getchar()) == EOF) exit(EXIT_FAILURE);
}

static void log_parse() {
    // fstream reverse read
    // pattern match ">>> emerge"
    // awk 2 fields: [1] of [3]
    //
    // parse popen() commands >>> static var e_cur / e_tot
    //
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $4}'
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $6}'
}

int main() {
    int i, match = 0;
    char str[] = "insects";

    read_char();
    for (i=0; str[i] != '\0'; i++) {
        if (c == str[i]) {
            match = 1;
            putchar(c);
            read_char();
        }
        else if (match) {
            match = 0;
            i = -1;
        }
        else {
            i= -1;
            putchar(c);
            read_char();
        }
    }


    return 0;
}
