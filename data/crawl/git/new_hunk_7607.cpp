		int recno;

		if (!spec) {
			status |= error("Not a reflog: %s", argv[i]);
			continue;
		}
