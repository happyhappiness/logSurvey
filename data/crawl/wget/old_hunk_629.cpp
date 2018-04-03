         token on the next line. */
      if (remaining_chars <= strlen (token)) 
        {
          printf ("\n%*c", leading_spaces, ' ');
          remaining_chars = line_length - leading_spaces;
        }
      printf ("%s ", token);
      remaining_chars -= strlen (token) + 1;  // account for " "
      token = strtok (NULL, " ");
    }

