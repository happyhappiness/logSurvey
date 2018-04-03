	if (argc > 2)
		die(_("too many params"));

	if (get_oid(object_ref, &object))
		die(_("Failed to resolve '%s' as a valid ref."), object_ref);

	if (strbuf_check_tag_ref(&ref, tag))
		die(_("'%s' is not a valid tag name."), tag);

	if (read_ref(ref.buf, prev.hash))
		oidclr(&prev);
	else if (!force)
		die(_("tag '%s' already exists"), tag);

