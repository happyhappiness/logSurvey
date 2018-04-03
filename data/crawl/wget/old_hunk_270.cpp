         In warc_write_end_record we will fill this space
         with information about the uncompressed and
         compressed size of the record. */
      fprintf (warc_current_file, "XXXXXXXXXXXX");
      fflush (warc_current_file);

      /* Start a new GZIP stream. */
