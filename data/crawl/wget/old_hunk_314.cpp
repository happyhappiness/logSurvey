          logprintf (LOG_NOTQUIET, "%s: %s\n", hs->local_file, strerror (errno));
          CLOSE_INVALIDATE (sock);
          xfree (head);
          return FOPENERR;
        }
    }
