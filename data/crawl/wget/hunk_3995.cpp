 		logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
 	      dt &= ~RETROKF;
 	    }
+
 	  /* If everything was OK, and links are to be converted, let's
 	     store the local filename.  */
 	  if (opt.convert_links && (dt & RETROKF) && (filename != NULL))
