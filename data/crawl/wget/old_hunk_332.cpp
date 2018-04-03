         token on the next line. */
      if (remaining_chars <= strlen (token))
        {
          printf ("\n%*c", TABULATION, ' ');
          remaining_chars = line_length - TABULATION;
        }
      printf ("%s ", token);
      remaining_chars -= strlen (token) + 1;  /* account for " " */
      token = strtok (NULL, " ");
    }

  printf ("\n");

  xfree (line_dup);
}

static void
