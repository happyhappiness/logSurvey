      CMDS->any_recurse flag.  */
 
   if (nlines > USHRT_MAX)
-    fatal (&cmds->fileinfo, _("Recipe has too many lines (%ud)"), nlines);
+    ON (fatal, &cmds->fileinfo, _("Recipe has too many lines (%ud)"), nlines);
 
   cmds->ncommand_lines = nlines;
   cmds->command_lines = lines;
