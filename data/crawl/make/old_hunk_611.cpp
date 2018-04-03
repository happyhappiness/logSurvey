              continue;
            }

          /* If it's a multi-line define / endef, manage that.  */
          if (vmod.define_v)
            {
              if (*p == '\0')
                fatal (fstart, _("empty variable name"));

              /* Let the variable name be the whole rest of the line,
                 with trailing blanks stripped (comments have already been
                 removed), so it could be a complex variable/function
                 reference that might contain blanks.  */
              p2 = p + strlen (p);
              while (isblank ((unsigned char)p2[-1]))
                --p2;
              v = do_define (p, p2 - p, origin, ebuf);
            }
          else
            {
              v = try_variable_definition (fstart, p, origin, 0);
              assert (v != NULL);
            }

          if (vmod.export_v)
            v->export = v_export;
