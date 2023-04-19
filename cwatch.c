// This program is licensed under the GNU Public License (GPL).
// All indentation is performed according to GNU indentation standards.
// This program is to be used AS IS, and does NOT include any WARRANTY,
// even for MERCHANTABILITY, or FITNESS FOR A PARTICULAR PURPOSE.


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
#include <argp.h>

static void prev_time ();
static void avg_time ();
static void pkg_hist ();
static void global_hist ();

static char c;
static char logdir[128];
static char std_dir[] = "/var/log/portage";
static char log_file[];

// static int e_cur;
// static int e_tot;
// static int usr_dir;

static int
parse_opt (int key, char *arg, struct argp_state *state)
{
  switch (key)
    {
    case 't':
      {
	prev_time ();
	break;
      };
    case 'T':
      {
	avg_time ();
	break;
      };
    case 'p':
      {
	pkg_hist ();
	break;
      };
    case 'g':
      {
	global_hist ();
	break;
      };
    }
  return 0;
}

int
get_logdir ()
{
  FILE *fpipe;
  char buf[128];
  char cmd[] = "portageq envvar EMERGE_LOG_DIR";

  if (0 == (fpipe = (FILE *) popen (cmd, "r")))
    {
      perror ("popen() failed.");
      exit (EXIT_FAILURE);
    }

  fread (&buf, sizeof buf, 128, fpipe);

  pclose (fpipe);

  if (buf[0] != '\0')
    strcpy (logdir, buf);
  // possible switch to strncpy()?
  else
    strcpy (logdir, std_dir);
  // possible switch to strncpy()?

  puts (logdir);

  return EXIT_SUCCESS;
}

/*
void
read_char ()
{
  if ((c = getchar ()) == EOF)
    exit (EXIT_FAILURE);
}

static void
log_parse ()
{
  // fstream reverse read
  // pattern match ">>> emerge"
  // awk 2 fields: [1] of [3]
  //
  // parse popen() commands >>> static var e_cur / e_tot
  //
  // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $4}'
  // cat /var/log/portage/emerge.log  | grep -w ">>> emerge" | awk '{print $6}'
}
*/

prev_time ()
{
  printf ("prev_time [ok]\n");
}

avg_time ()
{
  printf ("avg_time [ok]\n");
}

pkg_hist ()
{
  printf ("pkg_hist [ok]\n");
}

global_hist ()
{
  printf ("global_hist [ok]\n");
}

int
main (int argc, char **argv)
{
  struct argp_option options[] = {
    {"prevtime", 't', "<pkg>", 0, "Print the last build time for <pkg>"},
    {"avgtime", 'T', "<pkg>", 0, "Calculate the avg build time for <pkg>"},
    {"pkg-history", 'p', "<pkg>", 0, "Fetch emerge history for <pkg>"},
    {"global-history", 'g', 0, 0, "Fetch global emerge history"},
    {0}
  };
  struct argp argp = { options, parse_opt, 0, 0 };
  return argp_parse (&argp, argc, argv, 0, 0, 0);


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


  return 0;
}
