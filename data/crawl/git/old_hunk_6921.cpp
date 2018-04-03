	for (i = 0; i < argc; i++) {
		const char *src = source[i], *dst = destination[i];
		enum update_mode mode = modes[i];
		if (show_only || verbose)
			printf("Renaming %s to %s\n", src, dst);
		if (!show_only && mode != INDEX &&
