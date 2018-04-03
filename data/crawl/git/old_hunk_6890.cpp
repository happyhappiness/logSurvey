		free(collected.e);
	}

	while (i < argc) {
		const char *ref = argv[i++];
		unsigned char sha1[20];
		if (!resolve_ref(ref, sha1, 1, NULL)) {
			status |= error("%s points nowhere!", ref);
			continue;
		}
		set_reflog_expiry_param(&cb, explicit_expiry, ref);