		else if (oe) {
			if (oe->type != OBJ_COMMIT)
				die("Not a commit (actually a %s): %s",
					typename(oe->type), command_buf.buf);
		}
		/*
		 * Accept the sha1 without checking; it expected to be in
