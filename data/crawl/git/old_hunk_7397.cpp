	if (obj->flags & SEEN)
		return 0;
	obj->flags |= SEEN;
	if (obj->type == OBJ_BLOB)
		return 0;
	if (obj->type == OBJ_TREE)
