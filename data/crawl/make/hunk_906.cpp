   i =  atoi (argv[0]);
 
   if (i == 0)
-    fatal (reading_file, _("the `word' function takes a positive index argument"));
+    fatal (reading_file, _("first argument to `word' function must be greater than 0"));
 
 
   end_p = argv[1];
