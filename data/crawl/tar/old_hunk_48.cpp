	    ERROR ((0, 0, _("This does not look like a tar archive")));
	    return false;
	  }
	
        xheader_decode (&dummy); /* decodes values from the global header */
        tar_stat_destroy (&dummy);
	
	/* The initial global header must be immediately followed by
	   an extended PAX header for the first member in this volume.
	   However, in some cases tar may split volumes in the middle
