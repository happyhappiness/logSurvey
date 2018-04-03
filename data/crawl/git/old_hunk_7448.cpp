{
	struct object *obj = &blob->object;

	if (obj->flags & SEEN)
		return;
	obj->flags |= SEEN;
