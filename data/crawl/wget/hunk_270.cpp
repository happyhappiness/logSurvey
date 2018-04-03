          In warc_write_end_record we will fill this space
          with information about the uncompressed and
          compressed size of the record. */
-      fprintf (warc_current_file, "XXXXXXXXXXXX");
+      fseek (warc_current_file, EXTRA_GZIP_HEADER_SIZE, SEEK_CUR);
       fflush (warc_current_file);
 
       /* Start a new GZIP stream. */
