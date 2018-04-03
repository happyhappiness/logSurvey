					command_buf.buf);
		if (type != expected)
			die("Not a %s (actually a %s): %s",
				typename(expected), typename(type),
				command_buf.buf);
	}

