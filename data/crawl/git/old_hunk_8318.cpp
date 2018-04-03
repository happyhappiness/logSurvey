			continue;
		if (S_ISDIR(entry.mode))
			obj = &lookup_tree(entry.sha1)->object;
		else
			obj = &lookup_blob(entry.sha1)->object;
		refs->ref[i++] = obj;
	}
	set_object_refs(&item->object, refs);