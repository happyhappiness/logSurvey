/* Write a message indicating that we've just entered or
   left (according to ENTERING) the current directory.  */

static void
log_working_directory (entering)
     int entering;
{
  static int entered = 0;
  char *message = entering ? "Entering" : "Leaving";

  if (entering)
    entered = 1;
  else if (!entered)
    /* Don't print the leaving message if we
       haven't printed the entering message.  */
    return;

  if (print_data_base_flag)
    fputs ("# ", stdout);

