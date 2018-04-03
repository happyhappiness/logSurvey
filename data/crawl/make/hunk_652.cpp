 static char *
 func_word (char *o, char **argv, const char *funcname UNUSED)
 {
-  char *end_p=0;
-  int i=0;
-  char *p=0;
+  const char *end_p;
+  const char *p;
+  int i;
 
   /* Check the first argument.  */
   check_numeric (argv[0], _("non-numeric first argument to `word' function"));
-  i =  atoi (argv[0]);
+  i = atoi (argv[0]);
 
   if (i == 0)
     fatal (*expanding_var,
            _("first argument to `word' function must be greater than 0"));
 
-
   end_p = argv[1];
   while ((p = find_next_token (&end_p, 0)) != 0)
     if (--i == 0)
