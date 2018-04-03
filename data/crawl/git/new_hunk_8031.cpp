	} else if (!strcmp(cmd, "unbundle")) {
		if (nongit)
			die("Need a repository to unbundle.");
		return !!unbundle(&header, bundle_fd) ||
			list_bundle_refs(&header, argc, argv);
	} else
		usage(bundle_usage);
}
