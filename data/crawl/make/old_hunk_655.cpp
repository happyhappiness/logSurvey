          strncpy (in, path, len);
          in[len] = '\0';

          if
          (
#ifdef HAVE_REALPATH
            realpath (in, out)
#else
            abspath (in, out)
#endif
          )
            {
              o = variable_buffer_output (o, out, strlen (out));
              o = variable_buffer_output (o, " ", 1);
