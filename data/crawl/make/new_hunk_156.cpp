        to_file->cmds = from_file->cmds;
      else if (from_file->cmds != to_file->cmds)
        {
          size_t l = strlen (from_file->name);
          /* We have two sets of commands.  We will go with the
             one given in the rule explicitly mentioning this name,
             but give a message to let the user know what's going on.  */
          if (to_file->cmds->fileinfo.filenm != 0)
            error (&from_file->cmds->fileinfo,
                   l + strlen (to_file->cmds->fileinfo.filenm) + INTSTR_LENGTH,
                   _("Recipe was specified for file '%s' at %s:%lu,"),
                   from_file->name, to_file->cmds->fileinfo.filenm,
                   to_file->cmds->fileinfo.lineno);
          else
            error (&from_file->cmds->fileinfo, l,
                   _("Recipe for file '%s' was found by implicit rule search,"),
                   from_file->name);
          l += strlen (to_hname);
          error (&from_file->cmds->fileinfo, l,
                 _("but '%s' is now considered the same file as '%s'."),
                 from_file->name, to_hname);
          error (&from_file->cmds->fileinfo, l,
                 _("Recipe for '%s' will be ignored in favor of the one for '%s'."),
                 to_hname, from_file->name);
        }
