			die(_("invalid object '%s' given."), name);
		if (obj->type == OBJ_COMMIT)
			obj = &((struct commit *)obj)->tree->object;
		if (obj->type == OBJ_TREE) {
			obj->flags |= flags;
			add_object_array(obj, name, &ent);
			continue;
		}
		if (obj->type == OBJ_BLOB) {
			if (2 <= blobs)
				die(_("more than two blobs given: '%s'"), name);
			hashcpy(blob[blobs].sha1, obj->sha1);
			blob[blobs].name = name;
			blob[blobs].mode = entry->mode;
			blobs++;
			continue;

		}
		die(_("unhandled object '%s' given."), name);
	}
	if (rev.prune_data.nr) {
		if (!path)