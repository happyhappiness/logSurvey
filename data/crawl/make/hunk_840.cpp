 void
 print_file_data_base ()
 {
-  register unsigned int i, nfiles, per_bucket;
-  register struct file *file;
-
   puts (_("\n# Files"));
 
-  per_bucket = nfiles = 0;
-  for (i = 0; i < FILE_BUCKETS; ++i)
-    {
-      register unsigned int this_bucket = 0;
-
-      for (file = files[i]; file != 0; file = file->next)
-	{
-	  register struct file *f;
-
-	  ++this_bucket;
-
-	  for (f = file; f != 0; f = f->prev)
-	    print_file (f);
-	}
+  hash_map (&files, print_file);
 
-      nfiles += this_bucket;
-      if (this_bucket > per_bucket)
-	per_bucket = this_bucket;
-    }
+  fputs (_("\n# files hash-table stats:\n# "), stdout);
+  hash_print_stats (&files, stdout);
+}
 
-  if (nfiles == 0)
-    puts (_("\n# No files."));
-  else
-    {
-      printf (_("\n# %u files in %u hash buckets.\n"), nfiles, FILE_BUCKETS);
-#ifndef	NO_FLOAT
-      printf (_("# average %.3f files per bucket, max %u files in one bucket.\n"),
-	      ((double) nfiles) / ((double) FILE_BUCKETS), per_bucket);
-#endif
-    }
+void
+init_hash_files ()
+{
+  hash_init (&files, 1000, file_hash_1, file_hash_2, file_hash_cmp);
 }
 
 /* EOF */
