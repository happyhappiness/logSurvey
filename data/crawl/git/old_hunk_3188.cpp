			fprintf(stderr, "Server supports allow-tip-sha1-in-want\n");
		allow_unadvertised_object_request |= ALLOW_TIP_SHA1;
	}
	if (!server_supports("thin-pack"))
		args->use_thin_pack = 0;
	if (!server_supports("no-progress"))
