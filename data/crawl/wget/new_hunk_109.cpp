outputting to a regular file.\n"));
          exit (WGET_EXIT_GENERIC_ERROR);
        }
      if (!output_stream_regular && (opt.convert_links || opt.convert_file_only))
        {
          fprintf (stderr, _("--convert-links or --convert-file-only can be used together \
only if outputting to a regular file.\n"));
          exit (WGET_EXIT_GENERIC_ERROR);
        }
    }

#ifdef __VMS
