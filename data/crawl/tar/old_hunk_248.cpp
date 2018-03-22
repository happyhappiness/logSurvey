	}
      else
	{
	  sprintf (message, _("Could only read %lu of %lu bytes"),
		   (unsigned long) status, (unsigned long) bytes);
	  report_difference (message);
	}
