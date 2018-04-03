   int i;
 
   /* Check the first argument.  */
-  check_numeric (argv[0], _("non-numeric first argument to `word' function"));
+  check_numeric (argv[0], _("non-numeric first argument to 'word' function"));
   i = atoi (argv[0]);
 
   if (i == 0)
     fatal (*expanding_var,
-           _("first argument to `word' function must be greater than 0"));
+           _("first argument to 'word' function must be greater than 0"));
 
   end_p = argv[1];
   while ((p = find_next_token (&end_p, 0)) != 0)
