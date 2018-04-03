    = "%sNo rule to make target `%s'%s";
  static const char msg_parent[]
    = "%sNo rule to make target `%s', needed by `%s'%s";
  if (keep_going_flag || file->dontcare)
    {
      if (!file->dontcare && !file->shownerror)
        {
          if (file->parent == 0)
            error (NILF, msg_noparent, "*** ", file->name, ".");
          else
            error (NILF, msg_parent, "*** ",
                   file->name, file->parent->name, ".");
          file->shownerror = 1;
        }
      file->update_status = 2;
    }
  else
    {
      if (file->parent == 0)
        fatal (NILF, msg_noparent, "", file->name, "");
      else
        fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
    }
}

/* If FILE is not up to date, execute the commands for it.
