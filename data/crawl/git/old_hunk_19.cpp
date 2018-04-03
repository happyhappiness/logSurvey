	return;

 need_obj:
	buf = get_obj(&ref->objectname, &obj, &size, &eaten);
	if (!buf)
		die(_("missing object %s for %s"),
		    oid_to_hex(&ref->objectname), ref->refname);
	if (!obj)
		die(_("parse_object_buffer failed on %s for %s"),
		    oid_to_hex(&ref->objectname), ref->refname);

	grab_values(ref->value, 0, obj, buf, size);
	if (!eaten)
		free(buf);

	/*
	 * If there is no atom that wants to know about tagged