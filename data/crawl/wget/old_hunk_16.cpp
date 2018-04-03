      if (home)
        {
          file = aprintf ("%s/wget.ini", home);
          if (!file_exists_p (file))
            {
              xfree (file);
            }
