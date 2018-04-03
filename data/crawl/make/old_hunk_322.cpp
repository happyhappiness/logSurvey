             more than once.  Just give a warning since this is harmless.  */
          if (cmds != 0 && cmds == f->cmds)
            error (flocp,
                   _("target '%s' given more than once in the same rule."),
                   f->name);

          /* Check for two single-colon entries both with commands.
