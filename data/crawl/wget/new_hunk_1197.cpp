      exit (1);
    }
#endif
  if (opt.output_document)
    {
      if (opt.convert_links 
          && (nurl > 1 || opt.page_requisites || opt.recursive))
        {
          fputs (_("\
Cannot specify both -k and -O if multiple URLs are given, or in combination\n\
with -p or -r. See the manual for details.\n\n"), stdout);
          print_usage ();
          exit (1);
        }
      if (opt.page_requisites
          || opt.recursive)
        {
          logprintf (LOG_NOTQUIET, "%s", _("\
WARNING: combining -O with -r or -p will mean that all downloaded content\n\
will be placed in the single file you specified.\n\n"));
        }
      if (opt.timestamping)
        {
          fputs (_("\
Cannot specify -N if -O is given. See the manual for details.\n\n"), stdout);
          print_usage ();
          exit (1);
        }
    }

  if (!nurl && !opt.input_filename)
src/ChangeLog |  7 +++++
src/test.c    |  2 ++
src/url.c     | 98 +++++++++++++++++++++++++++++++++++++----------------------
3 files changed, 71 insertions(+), 36 deletions(-)
