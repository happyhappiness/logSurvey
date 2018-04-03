}

/* Print the usage message.  */
static int
print_usage (int error)
{
  return fprintf (error ? stderr : stdout,
                  _("Usage: %s [OPTION]... [URL]...\n"), exec_name);
}

/* Print the help message, describing all the available options.  If
