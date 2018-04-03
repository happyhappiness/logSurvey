			continue;
		if (!tail_match(pattern, ref->name))
			continue;
		if (show_symref_target && ref->symref)
			printf("ref: %s\t%s\n", ref->symref, ref->name);
		printf("%s\t%s\n", oid_to_hex(&ref->old_oid), ref->name);
		status = 0; /* we found something */
	}
	return status;
