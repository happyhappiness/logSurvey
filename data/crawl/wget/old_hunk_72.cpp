       (f->type == FT_PLAINFILE) && opt.preserve_perm)
        {
          if (f->perms)
            chmod (actual_target, f->perms);
          else
            DEBUGP (("Unrecognized permissions for %s.\n", actual_target));
        }
