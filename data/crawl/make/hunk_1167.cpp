       *line = '\0';
       line = next_token (++line);
       if (*line != '\0')
-	error (flocp,
-                        "Extraneous text after `%s' directive", cmdname);
+	error (flocp, _("Extraneous text after `%s' directive"), cmdname);
 
       s2 = variable_expand (s2);
       conditionals->ignoring[conditionals->if_cmds - 1]
