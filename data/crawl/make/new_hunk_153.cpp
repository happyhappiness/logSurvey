      if (d == 0)
        {
          if (errno)
            pfatal_with_name ("INTERNAL: readdir");
          break;
        }

