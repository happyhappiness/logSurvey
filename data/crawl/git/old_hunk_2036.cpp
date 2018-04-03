		if (pipe(fdin) < 0) {
			if (async->out > 0)
				close(async->out);
			return error("cannot create pipe: %s", strerror(errno));
		}
		async->in = fdin[1];
	}
