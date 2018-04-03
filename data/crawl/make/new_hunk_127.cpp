      char c;
      char *sep;
      int alevel = 0;   /* apostrophe level */
      int tmpstrlen;
      char *tmpstr;
      if (strlen (cmd) == 0)
        {
          printf (_("Error, empty command\n"));
