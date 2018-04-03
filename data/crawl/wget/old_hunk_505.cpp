          if (premature_token)
            {
              fprintf (stderr, _("\
%s: %s:%d: warning: \"%s\" token appears before any machine name\n"),
                       exec_name, path, ln, premature_token);
              premature_token = NULL;
            }

