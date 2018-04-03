      done = 0;

      for (;;)
        {
          errno = 0;
          if (iconv (cd, (ICONV_CONST char **) &fname, &inlen, &s, &outlen) == 0
              && iconv (cd, NULL, NULL, &s, &outlen) == 0)
            {
              *(converted_fname + len - outlen - done) = '\0';
              iconv_close (cd);
              DEBUGP (("Converted file name '%s' (%s) -> '%s' (%s)\n",
                       orig_fname, from_encoding, converted_fname, to_encoding));
              xfree (orig_fname);
              return converted_fname;
            }

          /* Incomplete or invalid multibyte sequence */
          if (errno == EINVAL || errno == EILSEQ || errno == 0)
            {
              if (errno)
                logprintf (LOG_VERBOSE,
                           _ ("Incomplete or invalid multibyte sequence encountered\n"));
              else
                logprintf (LOG_VERBOSE,
                           _ ("Unconvertable multibyte sequence encountered\n"));
              xfree (converted_fname);
              converted_fname = (char *) orig_fname;
              break;
            }
          else if (errno == E2BIG) /* Output buffer full */
            {
              done = len;
              len = outlen = done + inlen * 2;
              converted_fname = xrealloc (converted_fname, outlen + 1);
              s = converted_fname + done;
            }
          else /* Weird, we got an unspecified error */
            {
              logprintf (LOG_VERBOSE, _ ("Unhandled errno %d\n"), errno);
              xfree (converted_fname);
              converted_fname = (char *) orig_fname;
              break;
            }
        }
      DEBUGP (("Failed to convert file name '%s' (%s) -> '?' (%s)\n",
               orig_fname, from_encoding, to_encoding));
    }

    iconv_close(cd);
