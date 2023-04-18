/**** TO DO ****/

/* Move repeatedly used functions / basic definitions to lib.h
Populate functions
Create first public release */


/** includes **/
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

static int e_cur;
static int e_tot;

char c;
static char logdir[128];

void arg_parse () {
    // add flags for functions
    // v,g,h,s,t,T
}

int get_logdir () {
    FILE *fpipe;
    char buf[128];
    char cmd[] = "portageq envvar EMERGE_LOG_DIR";
    
    if (0 == (fpipe = (FILE*)popen (cmd, "r"))) {
        perror ("popen() failed.");
        exit (EXIT_FAILURE);
    }

    fread (&buf, sizeof buf, 128, fpipe);
    
    pclose (fpipe);

    if (buf[0] != '\0')
        strcpy(logdir, buf);
    else
        exit (EXIT_FAILURE);
        // temporary, option will be enabled soon

    puts(logdir);

    return EXIT_SUCCESS;
}

void read_char () {
    if ((c = getchar ()) == EOF) exit(EXIT_FAILURE);
}

static void log_parse () {
    // fstream reverse read
    // pattern match ">>> emerge"
    // awk 2 fields: [1] of [3]
    //
    // parse popen() commands >>> static var e_cur / e_tot
    //
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $4}'
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $6}'
}

int main () {
    /*
    int i, match = 0;
    char str[] = "insects";

    read_char ();
    for (i=0; str[i] != '\0'; i++) {
        if (c == str[i]) {
            match = 1;
            putchar (c);
            read_char ();
        }
        else if (match) {
            match = 0;
            i = -1;
        }
        else {
            i= -1;
            putchar (c);
            read_char ();
        }
    }
    */
    get_logdir();
    return 0;
}
