          logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
          ret = err;
          goto exit;
        case NEWLOCATION:
          /* Return the new location to the caller.  */
          if (!*newloc)
