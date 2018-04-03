			free((char *)refspecs[i]);
		}
		free(refspecs);
	} else if (data->import || data->bidi_import || data->export) {
		warning("This remote helper should implement refspec capability.");
	}
	strbuf_release(&buf);
	if (debug)