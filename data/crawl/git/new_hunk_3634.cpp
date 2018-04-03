		if (obj->type == OBJ_COMMIT)
			obj = &((struct commit *)obj)->tree->object;
		if (obj->type == OBJ_TREE) {
			obj->flags |= flags;
			add_object_array(obj, name, &ent);
			continue;
		}
		if (obj->type == OBJ_BLOB) {
