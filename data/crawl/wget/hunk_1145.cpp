 
   if (!check_user_specified_header (val))
     {
-      fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
-               exec_name, com, val);
+      fprintf (stderr, _("%s: %s: Invalid header %s.\n"),
+               exec_name, com, quote (val));
       return false;
     }
   opt.user_headers = vec_append (opt.user_headers, val);
