			return error(_("reading from '%s' beyond a symbolic link"), name);
		} else {
			if (read_old_data(st, name, buf))
				return error(_("read of %s failed"), name);
		}
	}
	return 0;
