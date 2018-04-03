
		sprintf(pathname + len, "%02x/", i);
		d = opendir(pathname);
		if (!d)
			continue;
		prune_dir(i, d, pathname, len + 3, opts);
		closedir(d);
	}
	if (opts == VERBOSE)
		stop_progress(&progress);
}

int cmd_prune_packed(int argc, const char **argv, const char *prefix)