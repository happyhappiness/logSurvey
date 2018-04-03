	if (!ref)
		return 1;

	while (ref) {
		if (check_ref_type(ref, flags))
			printf("%s	%s\n", sha1_to_hex(ref->old_sha1), ref->name);
		ref = ref->next;
	}
	return 0;
}