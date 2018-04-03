      if (HYPHENP (opt.output_document))
        {
#ifdef WINDOWS
          _setmode (_fileno (stdout), _O_BINARY);
#endif
          output_stream = stdout;
        }
