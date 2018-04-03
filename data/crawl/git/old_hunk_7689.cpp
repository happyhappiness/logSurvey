		break;
	}

	if (!dest || i != argc - 1)
		usage(ls_remote_usage);

	remote = nongit ? NULL : remote_get(dest);
	if (remote && !remote->url_nr)
		die("remote %s has no configured URL", dest);
