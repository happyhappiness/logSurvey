	struct tag *tag;
	int i;

	hash_sha1_file(extra->value, extra->len, type_name(OBJ_TAG), tag_oid.hash);
	tag = lookup_tag(&tag_oid);
	if (!tag)
		die(_("bad mergetag in commit '%s'"), ref);
