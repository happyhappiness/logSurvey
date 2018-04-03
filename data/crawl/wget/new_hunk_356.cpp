
/* Print the usage message.  */
static void
print_usage (int error)
{
  fprintf (error ? stderr : stdout, _("Usage: %s [OPTION]... [URL]...\n"),
           exec_name);
}

/* Print the help message, describing all the available options.  If
