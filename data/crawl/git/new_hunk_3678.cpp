
	if (!strcmp(data->refname, entry->name))
		return 0;
	if (entry->flag & REF_ISBROKEN) {
		/* This shouldn't happen to packed refs. */
		error("%s is broken!", entry->name);
		return 0;
	}
	if (!has_sha1_file(entry->u.value.sha1)) {
		unsigned char sha1[20];
		int flags;

		if (read_ref_full(entry->name, sha1, 0, &flags))
			/* We should at least have found the packed ref. */
			die("Internal error");
		if ((flags & REF_ISSYMREF) || !(flags & REF_ISPACKED))
			/*
			 * This packed reference is overridden by a
			 * loose reference, so it is OK that its value
			 * is no longer valid; for example, it might
			 * refer to an object that has been garbage
			 * collected.  For this purpose we don't even
			 * care whether the loose reference itself is
			 * invalid, broken, symbolic, etc.  Silently
			 * omit the packed reference from the output.
			 */
			return 0;
		/*
		 * There is no overriding loose reference, so the fact
		 * that this reference doesn't refer to a valid object
		 * indicates some kind of repository corruption.
		 * Report the problem, then omit the reference from
		 * the output.
		 */
		error("%s does not point to a valid object!", entry->name);
		return 0;
	}

	len = snprintf(line, sizeof(line), "%s %s\n",
		       sha1_to_hex(entry->u.value.sha1), entry->name);
	/* this should not happen but just being defensive */