		if (pipe(fdin) < 0) {
			if (async->out > 0)
				close(async->out);
			return error_errno("cannot create pipe");
		}
		async->in = fdin[1];
	}
