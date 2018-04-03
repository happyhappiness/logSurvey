  if (file->double_colon && file->deps == 0)
    {
      must_make = 1;
      DEBUGPR (_("Target `%s' is double-colon and has no prerequisites.\n"));
    }
  else if (!noexist && file->is_target && !deps_changed && file->cmds == 0)
    {
      must_make = 0;
      DEBUGPR (_("No commands for `%s' and no prerequisites actually changed.\n"));
    }

  if (!must_make)
    {
      if (debug_flag)
        {
          print_spaces(depth);
          printf(_("No need to remake target `%s'"), file->name);
          if (!streq(file->name, file->hname))
              printf(_("; using VPATH name `%s'"), file->hname);
          printf(".\n");
          fflush(stdout);
        }

      notice_finished_file (file);
