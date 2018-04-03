
    if (temp == NULL || c == ':')
      {
        if (opterr)
          {
#if 0
            if (c < 040 || c >= 0177)
              fprintf (stderr, "%s: unrecognized option, character code 0%o\n",
                       exec_name, c);
            else
              fprintf (stderr, "%s: unrecognized option `-%c'\n", exec_name, c);
#else
            /* 1003.2 specifies the format of this message.  */
            fprintf (stderr, _("%s: illegal option -- %c\n"), exec_name, c);
#endif
          }
        optopt = c;
        return '?';
      }
    if (temp[1] == ':')
      {
        if (temp[2] == ':')
          {
            /* This is an option that accepts an argument optionally.  */
            if (*nextchar != '\0')
              {
                optarg = nextchar;
                optind++;
              }
            else
              optarg = 0;
            nextchar = NULL;
          }
        else
          {
            /* This is an option that requires an argument.  */
            if (*nextchar != '\0')
              {
                optarg = nextchar;
                /* If we end this ARGV-element by taking the rest as an arg,
                   we must advance to the next element now.  */
                optind++;
              }
            else if (optind == argc)
              {
                if (opterr)
                  {
#if 0
                    fprintf (stderr, "%s: option `-%c' requires an argument\n",
                             exec_name, c);
#else
                    /* 1003.2 specifies the format of this message.  */
                    fprintf (stderr, _("%s: option requires an argument -- %c\n"),
                             exec_name, c);
#endif
                  }
                optopt = c;
                if (optstring[0] == ':')
                  c = ':';
                else
                  c = '?';
              }
            else
              /* We already incremented `optind' once;
                 increment it again when taking next ARGV-elt as argument.  */
              optarg = argv[optind++];
            nextchar = NULL;
          }
      }
    return c;
  }
}

/* Calls internal getopt function to enable long option names.  */
int
getopt_long (int argc, char *const *argv, const char *shortopts,
	     const struct option *longopts, int *longind)
{
  return _getopt_internal (argc, argv, shortopts, longopts, longind, 0);
}

int
getopt (int argc, char *const *argv, const char *optstring)
{
  return _getopt_internal (argc, argv, optstring,
                           (const struct option *) 0,
                           (int *) 0,
                           0);
}

#endif        /* _LIBC or not __GNU_LIBRARY__.  */

#ifdef TEST

