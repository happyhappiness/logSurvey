				close_pair(fdin);
			else if (async->in)
				close(async->in);
			return error("cannot create pipe: %s", strerror(errno));
		}
		async->out = fdout[0];
	}
