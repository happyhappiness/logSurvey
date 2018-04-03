			continue;
		}

		if (1 < opts.index_only + opts.update)
			die("-u and -i at the same time makes no sense");

		if (get_sha1(arg, sha1))
			die("Not a valid object name %s", arg);
