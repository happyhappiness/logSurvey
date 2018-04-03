#endif
      last_retr_err = retr_err == RETROK ? last_retr_err : retr_err;

      /* Remove the file if error encountered or if option specified.
         Note: the file has been downloaded using *_loop. Therefore, it
         is not necessary to keep the file for continuated download.  */
      if ((retr_err != RETROK || opt.delete_after)
           && filename != NULL && file_exists_p (filename))
        {
          logprintf (LOG_VERBOSE, _("Removing %s.\n"), quote (filename));
          if (unlink (filename))
            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
        }
      if (output_stream)
        {
