	}
	if (!strcmp(cmd, "create")) {
		if (!startup_info->have_repository)
			die(_("Need a repository to create a bundle."));
		return !!create_bundle(&header, bundle_file, argc, argv);
	} else if (!strcmp(cmd, "unbundle")) {
		if (!startup_info->have_repository)
			die(_("Need a repository to unbundle."));
		return !!unbundle(&header, bundle_fd) ||
			list_bundle_refs(&header, argc, argv);
	} else