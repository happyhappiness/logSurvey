		logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
	    }
	}

      /* Restore the original leave-pendingness.  */
      if (orig_lp)
	con->cmd |= LEAVE_PENDING;
