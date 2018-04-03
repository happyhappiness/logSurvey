		const char *parent = "HEAD";

		if (!active_nr && read_cache() < 0)
			die("Cannot read index");

		if (amend)
			parent = "HEAD^1";
