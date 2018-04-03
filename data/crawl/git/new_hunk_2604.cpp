			continue;
		if (!tail_match(pattern, ref->name))
			continue;
		printf("%s	%s\n", oid_to_hex(&ref->old_oid), ref->name);
		status = 0; /* we found something */
	}
	return status;
