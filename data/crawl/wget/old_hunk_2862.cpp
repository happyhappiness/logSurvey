  return 1;
}

/* Store the lockable_boolean {2, 1, 0, -1} value from VAL to PLACE.
   COM is ignored, except for error messages.  Values 2 and -1
   indicate that once defined, the value may not be changed by
   successive wgetrc files or command-line arguments.

   Values: 2 - Enable a particular option for good ("always")
           1 - Enable an option ("on")
           0 - Disable an option ("off")
          -1 - Disable an option for good ("never")

   #### This hack is currently only used for passive FTP because a
   contributor had broken scripts specify --passive-ftp where he
   didn't want it.  It should be removed because the same can now be
   achieved by replacing the wget executable with a script containing:

       exec wget "$@" --no-passive-ftp
*/

static int
cmd_lockable_boolean (const char *com, const char *val, void *place)
{
  int lockable_boolean_value;

  int oldval = *(int *)place;

  /*
   * If a config file said "always" or "never", don't allow command line
   * arguments to override the config file.
   */
  if (oldval == -1 || oldval == 2)
    return 1;

  if (CMP2 (val, 'o', 'n') || CMP3 (val, 'y', 'e', 's') || CMP1 (val, '1'))
    lockable_boolean_value = 1;
  else if (CMP3 (val, 'o', 'f', 'f') || CMP2 (val, 'n', 'o') || CMP1 (val, '0'))
    lockable_boolean_value = 0;
  else if (0 == strcasecmp (val, "always"))
    lockable_boolean_value = 2;
  else if (0 == strcasecmp (val, "never"))
    lockable_boolean_value = -1;
  else
    {
      fprintf (stderr,
	       _("%s: %s: Invalid extended boolean `%s';\n\
use one of `on', `off', `always', or `never'.\n"),
	       exec_name, com, val);
      return 0;
    }

  *(int *)place = lockable_boolean_value;
  return 1;
}

/* Set the non-negative integer value from VAL to PLACE.  With
   incorrect specification, the number remains unchanged.  */
static int
