       *line = '\0';
       line = next_token (++line);
       if (*line != '\0')
-	error (flocp, _("Extraneous text after `%s' directive"), cmdname);
+	EXTRANEOUS ();
 
       s2 = variable_expand (s2);
-      conditionals->ignoring[conditionals->if_cmds - 1]
-	= streq (s1, s2) == notdef;
+      conditionals->ignoring[o] = (streq (s1, s2) == (cmdtype == c_ifneq));
     }
 
+ DONE:
   /* Search through the stack to see if we're ignoring.  */
   for (i = 0; i < conditionals->if_cmds; ++i)
     if (conditionals->ignoring[i])
