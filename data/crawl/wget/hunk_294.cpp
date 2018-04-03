   fprintf (warc_tmp_fp, "%s\n", program_argstring);
 
   warc_write_resource_record (manifest_uuid,
-                              "metadata://gnu.org/software/wget/warc/wget_arguments.txt",
+                   "metadata://gnu.org/software/wget/warc/wget_arguments.txt",
                               NULL, NULL, NULL, "text/plain",
                               warc_tmp_fp, -1);
   /* warc_write_resource_record has closed warc_tmp_fp. */
