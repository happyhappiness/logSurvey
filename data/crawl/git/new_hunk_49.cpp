					command_buf.buf);
		if (type != expected)
			die("Not a %s (actually a %s): %s",
				type_name(expected), type_name(type),
				command_buf.buf);
	}

