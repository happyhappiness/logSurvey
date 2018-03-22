	    {
	      char message[MESSAGE_BUFFER_SIZE];

	      sprintf (message, _("Could only read %lu of %lu bytes"),
		       (unsigned long) status, (unsigned long) chunk_size);
	      report_difference (message);
	    }
