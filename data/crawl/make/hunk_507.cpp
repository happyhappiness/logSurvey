 	EXTRANEOUS ();
 
       if (!conditionals->if_cmds)
-	fatal (flocp, _("extraneous `%s'"), cmdname);
+	fatal (flocp, _("extraneous '%s'"), cmdname);
 
       --conditionals->if_cmds;
 
