              but give a message to let the user know what's going on.  */
           if (to_file->cmds->fileinfo.filenm != 0)
             error (&from_file->cmds->fileinfo,
-                   _("Commands were specified for file `%s' at %s:%lu,"),
+                   _("Recipe was specified for file `%s' at %s:%lu,"),
                    from_file->name, to_file->cmds->fileinfo.filenm,
                    to_file->cmds->fileinfo.lineno);
           else
             error (&from_file->cmds->fileinfo,
-                   _("Commands for file `%s' were found by implicit rule search,"),
+                   _("Recipe for file `%s' was found by implicit rule search,"),
                    from_file->name);
           error (&from_file->cmds->fileinfo,
                  _("but `%s' is now considered the same file as `%s'."),
                  from_file->name, to_hname);
           error (&from_file->cmds->fileinfo,
-                 _("Commands for `%s' will be ignored in favor of those for `%s'."),
+                 _("Recipe for `%s' will be ignored in favor of the one for `%s'."),
                  to_hname, from_file->name);
         }
     }
