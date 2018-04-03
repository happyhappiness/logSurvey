       exit (WGET_EXIT_GENERIC_ERROR);
     }
 
-  if (!file_exists_p (env))
-    {
-      fprintf (stderr, _("%s points to %s, which does not exist.\n"),
-              env_name, env);
-      exit (WGET_EXIT_GENERIC_ERROR);
-    }
-
   return cmd_string (com, env, place);
 }
 
