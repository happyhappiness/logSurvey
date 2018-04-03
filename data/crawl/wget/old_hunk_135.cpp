          if (fstat (fileno (output_stream), &st) == 0 && S_ISREG (st.st_mode))
            output_stream_regular = true;
        }
      if (!output_stream_regular && opt.convert_links)
        {
          fprintf (stderr, _("-k can be used together with -O only if \
outputting to a regular file.\n"));
          print_usage (1);
          exit (WGET_EXIT_GENERIC_ERROR);
        }
    }
