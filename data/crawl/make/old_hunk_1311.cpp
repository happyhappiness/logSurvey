            {
            case w_eol:
              if (cmdleft != 0)
                makefile_fatal (filename, lineno,
                                "missing rule before commands");
              else
                /* This line contained a variable reference that
