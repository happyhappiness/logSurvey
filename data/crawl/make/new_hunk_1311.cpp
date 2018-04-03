            {
            case w_eol:
              if (cmdleft != 0)
                fatal (&fileinfo,
                                "missing rule before commands");
              else
                /* This line contained a variable reference that
