      exit (1);
    }
#endif
  if (opt.output_document
      && (opt.page_requisites
          || opt.recursive
          || opt.timestamping))
    {
          printf (_("Cannot specify -r, -p or -N if -O is given.\n"));
          print_usage ();
          exit (1);
    }
  if (opt.output_document
      && opt.convert_links 
      && nurl > 1)
    {
          printf (_("Cannot specify both -k and -O if multiple URLs are given.\n"));
          print_usage ();
          exit (1);
    }

  if (!nurl && !opt.input_filename)
    {
      /* No URL specified.  */
