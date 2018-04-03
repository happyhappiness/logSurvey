
static int cmd_resolve_ref(struct ref_store *refs, const char **argv)
{
	struct object_id oid;
	const char *refname = notnull(*argv++, "refname");
	int resolve_flags = arg_flags(*argv++, "resolve-flags");
	int flags;
	const char *ref;

	ref = refs_resolve_ref_unsafe(refs, refname, resolve_flags,
				      &oid, &flags);
	printf("%s %s 0x%x\n", oid_to_hex(&oid), ref, flags);
	return ref ? 0 : 1;
}

