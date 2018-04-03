			free((char *)refspecs[i]);
		}
		free(refspecs);
	}
	strbuf_release(&buf);
	if (debug)