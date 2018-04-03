
	if (!revs->blob_objects)
		return;
	if (obj->flags & (UNINTERESTING | SEEN))
		return;
	obj->flags |= SEEN;
