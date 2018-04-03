 
   argv += 1 + !result;
 
-  if (argv[0])
+  if (*argv)
     {
-      char *expansion;
-
-      expansion = expand_argument (argv[0], NULL);
+      char *expansion = expand_argument (*argv, NULL);
 
       o = variable_buffer_output (o, expansion, strlen (expansion));
 
