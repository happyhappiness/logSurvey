	   Pretend it was successfully remade.  */
	file->update_status = 0;
      else
        {
          const char *msg_noparent
            = _("%sNo rule to make target `%s'%s");
          const char *msg_parent
            = _("%sNo rule to make target `%s', needed by `%s'%s");

          /* This is a dependency file we cannot remake.  Fail.  */
          if (!keep_going_flag && !file->dontcare)
            {
              if (file->parent == 0)
                fatal (NILF, msg_noparent, "", file->name, "");

              fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
            }

          if (!file->dontcare)
            {
              if (file->parent == 0)
                error (NILF, msg_noparent, "*** ", file->name, ".");
              else
                error (NILF, msg_parent, "*** ",
                       file->name, file->parent->name, ".");
            }
          file->update_status = 2;
        }
    }
  else
    {
