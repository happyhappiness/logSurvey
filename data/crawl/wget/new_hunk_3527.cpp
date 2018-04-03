	      cur_url->local_name = NULL;
	    }
	}

      /* Convert the links in the file.  */
      convert_links (html->string, urls);
      ++file_count;

      /* Free the data.  */
      free_urlpos (urls);
    }

  msecs = wtimer_elapsed (timer);
  wtimer_delete (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %.2f seconds.\n"),
	     file_count, (double)msecs / 1000);
}

/* Cleanup the data structures associated with recursive retrieving
