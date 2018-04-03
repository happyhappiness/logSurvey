 	      /* We have two sets of commands.  We will go with the
 		 one given in the rule explicitly mentioning this name,
 		 but give a message to let the user know what's going on.  */
-	      if (oldfile->cmds->filename != 0)
-		makefile_error (file->cmds->filename, file->cmds->lineno,
-				"Commands were specified for \
-file `%s' at %s:%u,",
-				oldname, oldfile->cmds->filename,
-				oldfile->cmds->lineno);
+	      if (oldfile->cmds->fileinfo.filenm != 0)
+                error (&file->cmds->fileinfo,
+                                "Commands were specified for \
+file `%s' at %s:%lu,",
+                                oldname, oldfile->cmds->fileinfo.filenm,
+                                oldfile->cmds->fileinfo.lineno);
 	      else
-		makefile_error (file->cmds->filename, file->cmds->lineno,
+		error (&file->cmds->fileinfo,
 				"Commands for file `%s' were found by \
 implicit rule search,",
 				oldname);
-	      makefile_error (file->cmds->filename, file->cmds->lineno,
+	      error (&file->cmds->fileinfo,
 			      "but `%s' is now considered the same file \
 as `%s'.",
 			      oldname, name);
-	      makefile_error (file->cmds->filename, file->cmds->lineno,
+	      error (&file->cmds->fileinfo,
 			      "Commands for `%s' will be ignored \
 in favor of those for `%s'.",
 			      name, oldname);
