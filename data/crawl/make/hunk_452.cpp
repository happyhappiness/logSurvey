   if (cmdtype == c_endif)
     {
       if (*line != '\0')
-	EXTRANEOUS ();
+        EXTRANEOUS ();
 
       if (!conditionals->if_cmds)
-	fatal (flocp, _("extraneous '%s'"), cmdname);
+        fatal (flocp, _("extraneous '%s'"), cmdname);
 
       --conditionals->if_cmds;
 
