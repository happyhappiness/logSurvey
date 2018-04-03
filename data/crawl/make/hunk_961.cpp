   char *shell, *ifs;
   char **argv;
 
+#ifdef VMS
+  char *cptr;
+  int argc;
+
+  argc = 0;
+  cptr = line;
+  for (;;)
+    {
+      while ((*cptr != 0)
+	     && (isspace (*cptr)))
+	cptr++;
+      if (*cptr == 0)
+	break;
+      while ((*cptr != 0)
+	     && (!isspace(*cptr)))
+	cptr++;
+      argc++;
+    }
+
+  argv = (char **)malloc (argc * sizeof (char *));
+  if (argv == 0)
+    abort ();
+
+  cptr = line;
+  argc = 0;
+  for (;;)
+    {
+      while ((*cptr != 0)
+	     && (isspace (*cptr)))
+	cptr++;
+      if (*cptr == 0)
+	break;
+      if (debug_flag)
+	printf ("argv[%d] = [%s]\n", argc, cptr);
+      argv[argc++] = cptr;
+      while ((*cptr != 0)
+	     && (!isspace(*cptr)))
+	cptr++;
+      if (*cptr != 0)
+	*cptr++ = 0;
+    }
+#else
   {
     /* Turn off --warn-undefined-variables while we expand SHELL and IFS.  */
     int save = warn_undefined_variables_flag;
