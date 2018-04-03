 # ifdef __EMX__
     case EINVAL:
       /* this nasty error was driving me nuts :-( */
-      error (NILF, _("spawnvpe: environment space might be exhausted"));
+      O (error, NILF, _("spawnvpe: environment space might be exhausted"));
       /* FALLTHROUGH */
 # endif
 
