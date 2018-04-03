Removing file due to --delete-after in retrieve_from_file():\n"));
          logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
          if (unlink (filename))
            logprintf (LOG_NOTQUIET, "Failed to unlink %s: (%d) %s\n", filename, errno, strerror (errno));
          dt &= ~RETROKF;
        }

