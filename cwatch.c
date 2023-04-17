/** includes **/

#include <stdio.h>
#include <stdlib.h>

static int e_cur;
static int e_tot;
int e_rem;

static char logdir[128];

int e_logdir() {
    FILE *fpipe;
    char buf[128];
    
    if (0 == (fpipe = (FILE*)popen("portageq envvar EMERGE_LOG_DIR", "r")))
    {
        perror ("popen() failed.");
        exit (EXIT_FAILURE);
    }

    fread(&buf, sizeof buf, 128, fpipe);
    
    /*
    if (  logdir empty string  )
        return 0; // logdir = /var/log/portage/
    else
        return 0; // logdir = &buf
    */
    pclose(fpipe);

    return EXIT_SUCCESS;
}

static void log_parse() {
    // fstream reverse read
    // pattern match ">>> energe"
    // awk 2 fields: [1] of [3]
    //
    // parse popen() commands >>> static var e_cur / e_tot
    //
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $4}'
    // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $6}'
}

int calc_rem() {
    e_rem = e_tot - e_cur + 1;
}



int main() {
    e_logdir(); 
    
    log_parse();
    calc_rem();
    



    return 0;
}
