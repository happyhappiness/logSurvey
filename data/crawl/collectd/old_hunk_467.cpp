		const char *error = lt_dlerror ();

		ERROR ("lt_dlopen failed: %s", error);
		return (1);
	}

