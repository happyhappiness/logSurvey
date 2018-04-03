		int recno;

		if (!spec) {
			status |= error("Not a reflog: %s", ref);
			continue;
		}
