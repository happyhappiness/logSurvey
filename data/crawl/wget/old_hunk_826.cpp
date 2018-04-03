         token on the next line. */
      if (remaining_chars <= strlen (token)) 
        {
          printf ("\n");
          int j = 0;
          for (j = 0; j < leading_spaces; j++) 
            {
              printf (" ");
