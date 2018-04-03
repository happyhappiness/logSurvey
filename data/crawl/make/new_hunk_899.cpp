
          if (wtype == w_varassign)
            {
              /* If there was a semicolon found, add it back, plus anything
                 after it.  */
              if (semip)
                {
                  *(--semip) = ';';
                  variable_buffer_output (p2 + strlen (p2),
                                          semip, strlen (semip)+1);
                }
              record_target_var (filenames, p, two_colon, v_origin, &fileinfo);
              filenames = 0;
              continue;
