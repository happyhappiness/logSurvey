 static void			/* Useful to call from gdb.  */
 print_rule (struct rule *r)
 {
-  register unsigned int i;
-  register struct dep *d;
+  unsigned int i;
+  struct dep *d;
 
-  for (i = 0; r->targets[i] != 0; ++i)
+  for (i = 0; i < r->num; ++i)
     {
       fputs (r->targets[i], stdout);
-      if (r->targets[i + 1] != 0)
-	putchar (' ');
-      else
-	putchar (':');
+      putchar ((i + 1 == r->num) ? ':' : ' ');
     }
   if (r->terminal)
     putchar (':');
