            {
            case w_eol:
              if (cmdleft != 0)
                fatal(&fileinfo, "missing rule before commands");
              /* This line contained something but turned out to be nothing
                 but whitespace (a comment?).  */
              continue;

            case w_colon:
            case w_dcolon:
