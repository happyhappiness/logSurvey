        }
      if (!output_stream_regular && opt.convert_links)
        {
          printf (_("-k can be used together with -O only if outputting to \
a regular file.\n"));
          print_usage ();
          exit(1);
        }
    }
