
	if (check_connectivity) {
		if (0 <= option_verbosity)
			printf(_("Checking connectivity... "));
		if (check_everything_connected_with_transport(iterate_ref_map,
							      0, &rm, transport))
			die(_("remote did not send all necessary objects"));
		if (0 <= option_verbosity)
			printf(_("done\n"));
	}

	if (refs) {
