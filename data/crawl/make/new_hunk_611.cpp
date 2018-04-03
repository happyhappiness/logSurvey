              continue;
            }

          if (vmod.define_v)
            v = do_define (p, origin, ebuf);
          else
            v = try_variable_definition (fstart, p, origin, 0);

          assert (v != NULL);

          if (vmod.export_v)
            v->export = v_export;
