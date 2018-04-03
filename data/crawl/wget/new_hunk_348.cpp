        }
      else if (opt.noclobber || opt.always_rest || opt.timestamping || opt.dirstruct
               || opt.output_document)
        {	  
	  if (opt.unlink && file_exists_p (con->target))
	    {
	      int res = unlink (con->target);
	      if (res < 0)
		{
		  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target,
			     strerror (errno));
		  fd_close (csock);
		  con->csock = -1;
		  fd_close (dtsock);
		  fd_close (local_sock);
		  return UNLINKERR;
		}
	    }

#ifdef __VMS
          int open_id;

