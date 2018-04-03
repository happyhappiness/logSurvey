Removing file due to --delete-after in retrieve_from_file():\n"));
          logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
          if (unlink (filename))
            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
          dt &= ~RETROKF;
        }

