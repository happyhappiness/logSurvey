                {
                  /* Sizes do not match */
                  logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %s) -- retrieving.\n\n"),
			     number_to_static_string (local_size));
                }
            }
	}	/* opt.timestamping && f->type == FT_PLAINFILE */
