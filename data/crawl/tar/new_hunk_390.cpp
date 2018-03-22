  return symbolic_oflag;
}

static struct option const long_opts[] =
{
  {"help", no_argument, 0, 'h'},
  {"version", no_argument, 0, 'v'},
  {0, 0, 0, 0}
};

static void
usage (int status)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
	     program_name);
  else
    {
      printf (_("\
Usage: %s [OPTION]\n\
Manipulate a tape drive, accepting commands from a remote process.\n\
\n\
  --version  Output version info.\n\
  --help  Output this help.\n"),
	      program_name);
      fputs (_("\nReport bugs to <bug-tar@gnu.org>.\n"), stdout);
    }

  exit (status);
}

/*---.
| ?  |
`---*/
