   char *p=0;
 
   /* Check the first argument.  */
-  check_numeric (argv[0], "non-numeric first argument to `word' function");
+  check_numeric (argv[0], _("non-numeric first argument to `word' function"));
   i =  atoi (argv[0]);
 
   if (i == 0)
-    fatal (reading_file, "the `word' function takes a positive index argument");
+    fatal (reading_file, _("the `word' function takes a positive index argument"));
 
 
   end_p = argv[1];
