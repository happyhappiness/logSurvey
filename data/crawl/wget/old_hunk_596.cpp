        }
      else /* Weird, we got an unspecified error */
        {
          logprintf (LOG_VERBOSE, "Unhandled errno %d\n", errno);
          break;
        }
    }
