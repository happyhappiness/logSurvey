		else
		  {
		    char buf[UINTMAX_STRSIZE_BOUND];
		    WARN ((0, 0,
			   _("%s: File shrank by %s bytes; padding with zeros"),
			   quotearg_colon (p),
			   STRINGIFY_BIGINT (sizeleft, buf)));
		    if (! ignore_failed_read_option)
		      exit_status = TAREXIT_FAILURE;
		    goto padit;		/* short read */
		  }
	      }
