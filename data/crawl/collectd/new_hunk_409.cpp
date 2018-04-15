		const char *error = lt_dlerror ();

		ERROR ("lt_dlopen failed: %s", error);
		fprintf (stderr, "lt_dlopen failed: %s\n", error);
		return (1);
	}

