			continue;
		}
		if (bases_count < ARRAY_SIZE(bases)-1) {
			unsigned char *sha = xmalloc(20);
			if (get_sha1(argv[i], sha))
				die("Could not parse object '%s'", argv[i]);
			bases[bases_count++] = sha;
		}
		else
			warning("Cannot handle more than %d bases. "
