
	if (!(obj->flags & FLAG_CHECKED)) {
		unsigned long size;
		int type = sha1_object_info(get_object_hash(*obj), &size);
		if (type <= 0)
			die(_("did not receive expected object %s"),
			      sha1_to_hex(obj->sha1));
