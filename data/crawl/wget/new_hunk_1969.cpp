          if (size >= FMT_MAX_LENGTH)  /* We have a huge buffer, */
            {                          /* maybe we have some wrong format string? */
              free (str);              /* In this case we must free already allocated memory, */
              logprintf (LOG_ALWAYS, 
                         _("%s: aprintf: text buffer is too big (%ld bytes), \
free already allocated memory and abort.\n"),
                         exec_name, size);  /* printout a log message */
              abort ();             /* and abort... */
            }
                                       /* else, we continue to grow our buffer. */
          size <<= 1;                  /* twice the old size */
