                  }
              }
            *t = '\0';
          }

        /* Create an argv list for the shell command line.  */
        {
          int n = 0;

          new_argv = xmalloc ((4 + sflags_len/2) * sizeof (char *));
          new_argv[n++] = xstrdup (shell);

          /* Chop up the shellflags (if any) and assign them.  */
          if (! shellflags)
            new_argv[n++] = xstrdup ("");
          else
            {
              const char *s = shellflags;
              char *t;
              unsigned int len;
              while ((t = find_next_token (&s, &len)) != 0)
                new_argv[n++] = xstrndup (t, len);
            }

          /* Set the command to invoke.  */
          new_argv[n++] = line;
          new_argv[n++] = NULL;
        }
	return new_argv;
      }

