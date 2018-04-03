			return error("unable to unlink old '%s' (%s)", path, strerror(errno));
	} else if (state->not_new)
		return 0;
	create_directories(path, len, state);
	return write_entry(ce, path, state, 0);
}
