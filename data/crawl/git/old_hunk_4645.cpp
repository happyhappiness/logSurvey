		}
		if (obj->type == OBJ_BLOB) {
			if (2 <= blobs)
				die("more than two blobs given: '%s'", name);
			hashcpy(blob[blobs].sha1, obj->sha1);
			blob[blobs].name = name;
			blob[blobs].mode = list->mode;
			blobs++;
			continue;

		}
		die("unhandled object '%s' given.", name);
	}
	if (rev.prune_data) {
		const char **pathspec = rev.prune_data;