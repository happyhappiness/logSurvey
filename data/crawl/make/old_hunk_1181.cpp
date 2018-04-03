      if (debug_flag)
        {
          print_spaces (depth);
          printf("  Ignoring VPATH name `%s'.\n", file->hname);
          fflush(stdout);
        }
      file->ignore_vpath = 1;
