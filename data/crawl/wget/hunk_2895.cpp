   return file;
 }
 
-static int parse_line PARAMS ((const char *, char **, char **, int *));
+/* Return values of parse_line. */
+enum parse_line {
+  line_ok,
+  line_empty,
+  line_syntax_error,
+  line_unknown_command
+};
+
+static enum parse_line parse_line PARAMS ((const char *, char **,
+					   char **, int *));
 static int setval_internal PARAMS ((int, const char *, const char *));
 
-/* Initialize variables from a wgetrc file.  */
+/* Initialize variables from a wgetrc file.  Returns zero (failure) if
+   there were errors in the file.  */
 
-static void
+static int
 run_wgetrc (const char *file)
 {
   FILE *fp;
   char *line;
   int ln;
+  int errcnt = 0;
 
   fp = fopen (file, "rb");
   if (!fp)
     {
       fprintf (stderr, _("%s: Cannot read %s (%s).\n"), exec_name,
 	       file, strerror (errno));
-      return;
+      return 1;			/* not a fatal error */
     }
   enable_tilde_expansion = 1;
   ln = 1;
   while ((line = read_whole_line (fp)) != NULL)
     {
-      char *com, *val;
-      int comind, status;
+      char *com = NULL, *val = NULL;
+      int comind;
 
       /* Parse the line.  */
-      status = parse_line (line, &com, &val, &comind);
-      xfree (line);
-      /* If everything is OK, set the value.  */
-      if (status == 1)
+      switch (parse_line (line, &com, &val, &comind))
 	{
+	case line_ok:
+	  /* If everything is OK, set the value.  */
 	  if (!setval_internal (comind, com, val))
-	    fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
-		     file, ln);
-	  xfree (com);
-	  xfree (val);
+	    {
+	      fprintf (stderr, _("%s: Error in %s at line %d.\n"),
+		       exec_name, file, ln);
+	      ++errcnt;
+	    }
+	  break;
+	case line_syntax_error:
+	  fprintf (stderr, _("%s: Syntax error in %s at line %d.\n"),
+		   exec_name, file, ln);
+	  ++errcnt;
+	  break;
+	case line_unknown_command:
+	  fprintf (stderr, _("%s: Unknown command `%s' in %s at line %d.\n"),
+		   exec_name, com, file, ln);
+	  ++errcnt;
+	  break;
+	case line_empty:
+	  break;
+	default:
+	  abort ();
 	}
-      else if (status == 0)
-	fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
-		 file, ln);
+      xfree_null (com);
+      xfree_null (val);
+      xfree (line);
       ++ln;
     }
   enable_tilde_expansion = 0;
   fclose (fp);
+
+  return errcnt == 0;
 }
 
 /* Initialize the defaults and run the system wgetrc and user's own
