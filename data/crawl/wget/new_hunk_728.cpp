         token on the next line. */
      if (remaining_chars <= strlen (token)) 
        {
          int j;
          printf ("\n");
          j = 0;
          for (j = 0; j < leading_spaces; j++) 
            {
              printf (" ");