			fprintf(stderr, "Server supports side-band\n");
		use_sideband = 1;
	}
	if (!server_supports("thin-pack"))
		args->use_thin_pack = 0;
	if (!server_supports("no-progress"))
