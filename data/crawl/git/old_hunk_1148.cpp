			if (!arg[2])
				break;
			if (parse_merge_opt(&o, arg + 2))
				die("Unknown option %s", arg);
			continue;
		}
		if (bases_count < ARRAY_SIZE(bases)-1) {
			struct object_id *oid = xmalloc(sizeof(struct object_id));
			if (get_oid(argv[i], oid))
				die("Could not parse object '%s'", argv[i]);
			bases[bases_count++] = oid;
		}
		else
			warning("Cannot handle more than %d bases. "
				"Ignoring %s.",
				(int)ARRAY_SIZE(bases)-1, argv[i]);
	}
	if (argc - i != 3) /* "--" "<head>" "<remote>" */
		die("Not handling anything other than two heads merge.");

	o.branch1 = argv[++i];
	o.branch2 = argv[++i];

	if (get_oid(o.branch1, &h1))
		die("Could not resolve ref '%s'", o.branch1);
	if (get_oid(o.branch2, &h2))
		die("Could not resolve ref '%s'", o.branch2);

	o.branch1 = better_branch_name(o.branch1);
	o.branch2 = better_branch_name(o.branch2);