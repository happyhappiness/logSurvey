
  if (!must_make)
    {
      if (debug_flag)
        {
          print_spaces(depth);
          printf("No need to remake target `%s'", file->name);
          if (!streq(file->name, file->hname))
              printf("; using VPATH name `%s'", file->hname);
          printf(".\n");
          fflush(stdout);
        }

      notice_finished_file (file);

      /* Since we don't need to remake the file, convert it to use the
         VPATH filename if we found one.  hfile will be either the
         local name if no VPATH or the VPATH name if one was found.  */

      while (file)
        {
          file->name = file->hname;
          file = file->prev;
        }

      return 0;
    }

  DEBUGPR ("Must remake target `%s'.\n");

  /* It needs to be remade.  If it's VPATH and not GPATH, toss the VPATH */
  if (!streq(file->name, file->hname))
    {
      char *name = file->name;

      if (gpath_search (&name, NULL))
        {
          register struct file *fp = file;

          /* Since we found the file on GPATH, convert it to use the
             VPATH filename. */
          while (fp)
            {
              fp->name = fp->hname;
              fp = fp->prev;
            }
          DEBUGPR ("  Using VPATH `%s' due to GPATH.\n");
        }
      else
        {
          if (debug_flag)
            {
              print_spaces (depth);
              printf("  Ignoring VPATH name `%s'.\n", file->hname);
              fflush(stdout);
            }
          file->ignore_vpath = 1;
        }
    }

  /* Now, take appropriate actions to remake the file.  */
  remake_file (file);

