	struct name_entry entry;
	struct name_path me;

	if (obj->flags & SEEN)
		return;
	obj->flags |= SEEN;