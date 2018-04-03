#endif
      last_retr_err = retr_err == RETROK ? last_retr_err : retr_err;

      /* Rename the file if error encountered; remove if option specified.
         Note: the file has been downloaded using *_loop. Therefore, it
         is not necessary to keep the file for continuated download.  */
      if ((retr_err != RETROK || opt.delete_after)
           && filename != NULL && file_exists_p (filename))
        {
          badhash_or_remove (filename);
        }
      if (output_stream)
        {
