      if (debug_flag)
        {
          print_spaces(depth);
          printf(_("No need to remake target `%s'"), file->name);
          if (!streq(file->name, file->hname))
              printf(_("; using VPATH name `%s'"), file->hname);
          printf(".\n");
          fflush(stdout);
        }
