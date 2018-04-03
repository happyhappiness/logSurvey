          /* Align the [ skipping ... ] line with the dots.  To do
             that, insert the number of spaces equal to the number of
             digits in the skipped amount in K.  */
          logprintf (LOG_PROGRESS, _("\n%*s[ skipping %sK ]"),
                     2 + skipped_k_len, "",
                     number_to_static_string (skipped_k));
        }

      logprintf (LOG_PROGRESS, "\n%6sK",
                 number_to_static_string (skipped / 1024));
      for (; remainder >= dot_bytes; remainder -= dot_bytes)
        {
          if (dp->dots % opt.dot_spacing == 0)
            logputs (LOG_PROGRESS, " ");
          logputs (LOG_PROGRESS, ",");
          ++dp->dots;
        }
      assert (dp->dots < opt.dots_in_line);
