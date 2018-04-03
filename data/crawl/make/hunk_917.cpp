      char **argv;
      const char *funcname;
 {
-  int i=0;
-  int j=0;
+  int start, count;
 
-  /* Check the first argument.  */
+  /* Check the arguments.  */
   check_numeric (argv[0],
 		 _("non-numeric first argument to `wordlist' function"));
-  i =atoi(argv[0]);
   check_numeric (argv[1],
 		 _("non-numeric second argument to `wordlist' function"));
 
-  j = atoi(argv[1]);
-
+  start = atoi (argv[0]);
+  count = atoi (argv[1]) - start + 1;
 
-  {
-    char *p;
-    char *end_p = argv[2];
+  if (count > 0)
+    {
+      char *p;
+      char *end_p = argv[2];
 
-    int start = (i < j) ? i : j;
-    int count = j -i ;
-    if (count < 0)
-      count = - count;
-    count ++;
+      /* Find the beginning of the "start"th word.  */
+      while (((p = find_next_token (&end_p, 0)) != 0) && --start)
+        ;
 
+      if (p)
+        {
+          /* Find the end of the "count"th word from start.  */
+          while (--count && (find_next_token (&end_p, 0) != 0))
+            ;
 
+          /* Return the stuff in the middle.  */
+          o = variable_buffer_output (o, p, end_p - p);
+        }
+    }
 
-    while (((p = find_next_token (&end_p, 0)) != 0) && --start)
-      {}
-    if (p)
-      {
-	while (--count && (find_next_token (&end_p, 0) != 0))
-	  {}
-	o = variable_buffer_output (o, p, end_p - p);
-      }
-  }
   return o;
 }
 
 static char*
-func_findstring(o, argv, funcname)
+func_findstring (o, argv, funcname)
      char *o;
      char **argv;
      const char *funcname;
