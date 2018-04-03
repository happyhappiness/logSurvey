      if (d == 0)
        {
          if (errno)
            fatal (NILF, "INTERNAL: readdir: %s\n", strerror (errno));
          break;
        }

