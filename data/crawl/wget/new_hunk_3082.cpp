	    }
	}
      request_set_header (req, "Content-Length",
			  xstrdup (number_to_static_string (post_data_size)),
			  rel_value);
    }

  /* Add the user headers. */
