		die("tag '%s' already exists", tag);

	if (annotate)
		create_tag(object, tag, &buf, message, sign, prev, object);

	lock = lock_any_ref_for_update(ref, prev, 0);
	if (!lock)
