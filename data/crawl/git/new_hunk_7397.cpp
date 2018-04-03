	if (obj->flags & SEEN)
		return 0;
	obj->flags |= SEEN;
	if (fsck_walk(obj, mark_used, 0))
		objerror(obj, "broken links");
	if (obj->type == OBJ_BLOB)
		return 0;
	if (obj->type == OBJ_TREE)
