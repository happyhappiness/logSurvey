   if (r->terminal)
     putchar (':');
 
-  for (d = r->deps; d != 0; d = d->next)
-    printf (" %s", dep_name (d));
-  putchar ('\n');
+  print_prereqs (r->deps);
 
   if (r->cmds != 0)
     print_commands (r->cmds);
