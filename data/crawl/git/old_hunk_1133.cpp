
	from_note = get_note(t, from_obj);
	if (!from_note) {
		retval = error(_("Missing notes on source object %s. Cannot "
			       "copy."), sha1_to_hex(from_obj));
		goto out;
	}
