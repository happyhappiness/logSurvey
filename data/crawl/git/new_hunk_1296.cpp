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
