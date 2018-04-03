   fputs (_("\n# files hash-table stats:\n# "), stdout);
   hash_print_stats (&files, stdout);
 }
+
+/* Verify the integrity of the data base of files.  */
+
+#define VERIFY_CACHED(_p,_n) \
+    do{\
+        if (_p->_n && _p->_n[0] && !strcache_iscached (_p->_n)) \
+          printf ("%s: Field %s not cached: %s\n", _p->name, # _n, _p->_n); \
+    }while(0)
+
+static void
+verify_file (const void *item)
+{
+  const struct file *f = item;
+  const struct dep *d;
+
+  VERIFY_CACHED (f, name);
+  VERIFY_CACHED (f, hname);
+  VERIFY_CACHED (f, vpath);
+  VERIFY_CACHED (f, stem);
+
+  /* Check the deps.  */
+  for (d = f->deps; d != 0; d = d->next)
+    {
+      VERIFY_CACHED (d, name);
+      VERIFY_CACHED (d, stem);
+    }
+}
+
+void
+verify_file_data_base (void)
+{
+  hash_map (&files, verify_file);
+}
 
 #define EXPANSION_INCREMENT(_l)  ((((_l) / 500) + 1) * 500)
 
