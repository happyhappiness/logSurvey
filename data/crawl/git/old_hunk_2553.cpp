
	if (!(obj->flags & FLAG_CHECKED)) {
		unsigned long size;
		int type = sha1_object_info(obj->sha1, &size);
		if (type <= 0)
			die(_("did not receive expected object %s"),
			      sha1_to_hex(obj->sha1));
