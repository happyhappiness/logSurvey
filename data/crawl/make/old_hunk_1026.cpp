          if (*lb_next != '\0')
            {
              unsigned int l = p2 - variable_buffer;
              plen = strlen(p2);
              (void)variable_buffer_output(p2+plen,
                                           lb_next, strlen(lb_next)+1);
              p2 = variable_buffer + l;
            }
          wtype = get_next_mword(p2, NULL, &p, &len);
          v_origin = o_file;
          if (wtype == w_static && (len == (sizeof("override")-1)
                                    && strneq(p, "override", len)))
            {
              v_origin = o_override;
              (void)get_next_mword(p+len, NULL, &p, &len);
            }
          else if (wtype != w_eol)
            wtype = get_next_mword(p+len, NULL, NULL, NULL);

          if (wtype == w_varassign || v_origin == o_override)
            {
              record_target_var(filenames, p, two_colon, v_origin, &fileinfo);
              filenames = 0;
              continue;
            }
