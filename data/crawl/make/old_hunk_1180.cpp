      if (debug_flag)
        {
          print_spaces(depth);
          printf("No need to remake target `%s'", file->name);
          if (!streq(file->name, file->hname))
              printf("; using VPATH name `%s'", file->hname);
          printf(".\n");
          fflush(stdout);
        }
