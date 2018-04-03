     }
 
   if (nfiles == 0)
-    puts ("\n# No files.");
+    puts (_("\n# No files."));
   else
     {
-      printf ("\n# %u files in %u hash buckets.\n", nfiles, FILE_BUCKETS);
+      printf (_("\n# %u files in %u hash buckets.\n"), nfiles, FILE_BUCKETS);
 #ifndef	NO_FLOAT
-      printf ("# average %.3f files per bucket, max %u files in one bucket.\n",
+      printf (_("# average %.3f files per bucket, max %u files in one bucket.\n"),
 	      ((double) nfiles) / ((double) FILE_BUCKETS), per_bucket);
 #endif
     }
