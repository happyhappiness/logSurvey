
	  p2 = next_token (variable_buffer);

          /* If the word we're looking at is EOL, see if there's _anything_
             on the line.  If not, a variable expanded to nothing, so ignore
             it.  If so, we can't parse this line so punt.  */
          if (wtype == w_eol)
            {
              if (*p2 != '\0')
                /* There's no need to be ivory-tower about this: check for
                   one of the most common bugs found in makefiles...  */
                fatal (&fileinfo, "missing separator%s",
                       strncmp(lb.buffer, "        ", 8) ? ""
                       : " (did you mean TAB instead of 8 spaces?)");
              continue;
            }

          /* Make the colon the end-of-string so we know where to stop
             looking for targets.  */
          *colonp = '\0';
