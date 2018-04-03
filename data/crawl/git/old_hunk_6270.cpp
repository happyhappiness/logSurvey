			continue;
		if (obj->type == OBJ_TAG) {
			obj->flags |= SEEN;
			add_object_array(obj, name, &objects);
			continue;
		}
		if (obj->type == OBJ_TREE) {
			process_tree(revs, (struct tree *)obj, &objects,
				     NULL, name);
			continue;
		}
		if (obj->type == OBJ_BLOB) {
			process_blob(revs, (struct blob *)obj, &objects,
				     NULL, name);
			continue;
		}
		die("unknown pending object %s (%s)",
		    sha1_to_hex(obj->sha1), name);
	}
	for (i = 0; i < objects.nr; i++)
		show_object(&objects.objects[i]);
	free(objects.objects);
	if (revs->pending.nr) {
		free(revs->pending.objects);
		revs->pending.nr = 0;
