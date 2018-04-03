			bases[bases_count++] = sha;
		}
		else
			warning("Cannot handle more than %zu bases. "
				"Ignoring %s.", ARRAY_SIZE(bases)-1, argv[i]);
	}
	if (argc - i != 3) /* "--" "<head>" "<remote>" */
		die("Not handling anything other than two heads merge.");