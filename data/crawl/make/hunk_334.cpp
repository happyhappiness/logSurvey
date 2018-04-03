       const struct dep *d;
       fputs (_("#  Also makes:"), stdout);
       for (d = f->also_make; d != 0; d = d->next)
-	printf (" %s", dep_name (d));
+        printf (" %s", dep_name (d));
       putchar ('\n');
     }
   if (f->last_mtime == UNKNOWN_MTIME)
