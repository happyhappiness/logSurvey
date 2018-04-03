	      cur_url->local_name = NULL;
	    }
	}
      /* Convert the links in the file.  */
      convert_links (html->string, urls);
      /* Free the data.  */
      free_urlpos (urls);
    }
}

/* Cleanup the data structures associated with recursive retrieving
