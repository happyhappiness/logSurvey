          retr_err = METALINK_SIG_ERROR;
          logprintf (LOG_NOTQUIET,
                     _("File %s retrieved but signature does not match. "
                       "\n"), quote (destname));
        }
#endif
      last_retr_err = retr_err == RETROK ? last_retr_err : retr_err;
