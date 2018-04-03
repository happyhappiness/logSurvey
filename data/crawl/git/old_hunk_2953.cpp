		struct argv_array paths = ARGV_ARRAY_INIT;
		int i;

		if (resume)
			die(_("Resolve operation not in progress, we are not resuming."));
