			result = options->walk(&lookup_blob(entry.sha1)->object, OBJ_BLOB, data, options);
		else {
			result = error("in tree %s: entry %s has bad mode %.6o",
					sha1_to_hex(tree->object.sha1), entry.path, entry.mode);
		}
		if (result < 0)
			return result;