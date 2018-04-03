     {
       if (!file_exists_p (env))
 	{
-	  fprintf (stderr, "%s: %s: %s.\n", exec_name, env, strerror (errno));
+	  fprintf (stderr, _("%s: WGETRC points to %s, which doesn't exist.\n"),
+		   exec_name, env);
 	  exit (1);
 	}
       return xstrdup (env);
