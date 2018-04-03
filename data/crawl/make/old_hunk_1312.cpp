
              wtype = get_next_mword(lb_next, NULL, &lb_next, &len);
              if (wtype == w_eol)
                makefile_fatal (filename, lineno, "missing separator");

              p2 += strlen(p2);
              *(p2++) = ' ';
