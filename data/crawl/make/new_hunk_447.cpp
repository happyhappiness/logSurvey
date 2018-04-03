            putenv (allocated_variable_expand (p));
          }

          if (ISDB (DB_BASIC))
            {
              char **p;
              printf (_("Re-executing[%u]:"), restarts);
              for (p = nargv; *p != 0; ++p)
                printf (" %s", *p);
              putchar ('\n');
            }

#ifndef _AMIGA
          {
