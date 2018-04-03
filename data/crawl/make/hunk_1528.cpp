       ++rules;
 
       putchar ('\n');
-      for (i = 0; r->targets[i] != 0; ++i)
-	{
-	  fputs (r->targets[i], stdout);
-	  if (r->targets[i + 1] != 0)
-	    putchar (' ');
-	  else
-	    putchar (':');
-	}
-      if (r->terminal)
-	{
-	  ++terminal;
-	  putchar (':');
-	}
+      print_rule (r);
 
-      for (d = r->deps; d != 0; d = d->next)
-	printf (" %s", dep_name (d));
-      putchar ('\n');
-
-      if (r->cmds != 0)
-	print_commands (r->cmds);
+      if (r->terminal)
+	++terminal;
     }
 
   if (rules == 0)
