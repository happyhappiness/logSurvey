      if (!file->dontcare)
        {
          if (file->parent == 0)
            error (NILF, msg_noparent, "*** ", file->name, ".");
          else
            error (NILF, msg_parent, "*** ",
                   file->name, file->parent->name, ".");
          file->shownerror = 1;
        }
