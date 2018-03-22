or a file name starting with `/' or `.', in which case the file's date is used.\n\
*This* `tar' defaults to `-f%s -b%d'.\n"),
	      DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
      fputs (_("\nReport bugs to <bug-tar@gnu.org>.\n"), stdout);
    }
  exit (status);
}
