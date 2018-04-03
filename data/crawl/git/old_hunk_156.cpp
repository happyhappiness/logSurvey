
	ref = refs_resolve_ref_unsafe(refs, refname, resolve_flags,
				      sha1, &flags);
	printf("%s %s 0x%x\n", sha1_to_hex(sha1), ref, flags);
	return ref ? 0 : 1;
}
