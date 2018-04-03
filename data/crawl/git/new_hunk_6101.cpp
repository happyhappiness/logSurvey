	}
	subkey = strrchr(name, '.');
	if (!subkey)
		return 0;
	remote = make_remote(name, subkey - name);
	remote->origin = REMOTE_CONFIG;
	if (!strcmp(subkey, ".mirror"))