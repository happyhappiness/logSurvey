          {
          case w_eol:
            if (cmdleft != 0)
              fatal (fstart, _("missing rule before recipe"));
            /* This line contained something but turned out to be nothing
               but whitespace (a comment?).  */
            continue;
