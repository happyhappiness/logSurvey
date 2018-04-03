   if (!unregister_ptr (ptr))
     {
       fprintf (stderr, "%s: bad xfree(%0*lx) at %s:%d\n",
-	       exec_name, 2 * sizeof (void *), (long) ptr,
-	       source_file, source_line);
+	       exec_name, PTR_FORMAT (ptr), source_file, source_line);
       abort ();
     }
   ++free_count;
