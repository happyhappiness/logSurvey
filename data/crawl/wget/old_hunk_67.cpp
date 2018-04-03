      if (retr_err != RETROK)
        {
          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
                     quote (filename ? filename : mfile->name));
        }
      else if (!hash_ok)
        {
          retr_err = METALINK_CHKSUM_ERROR;
          logprintf (LOG_NOTQUIET,
                     _("File %s retrieved but checksum does not match. "
                       "\n"), quote (filename));
        }
#ifdef HAVE_GPGME
        /* Signature will be only validated if hash check was successful.  */
