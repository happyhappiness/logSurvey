				close_pair(fdin);
			else if (async->in)
				close(async->in);
			return error_errno("cannot create pipe");
		}
		async->out = fdout[0];
	}
