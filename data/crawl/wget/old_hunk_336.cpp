      if (HYPHENP (opt.output_document))
        {
#ifdef WINDOWS
          FILE *result;
          result = freopen ("CONOUT$", "wb", stdout);
          if (result == NULL)
            {
              logputs (LOG_NOTQUIET, _("\
WARNING: Can't reopen standard output in binary mode;\n\
         downloaded file may contain inappropriate line endings.\n"));
            }
#endif
          output_stream = stdout;
        }
