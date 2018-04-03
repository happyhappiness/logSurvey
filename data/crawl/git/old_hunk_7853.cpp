		if (!path_list_has_path(&existing_refs, ref_name) &&
		    !path_list_has_path(&new_refs, ref_name) &&
		    lookup_object(ref->old_sha1)) {
			fprintf(stderr, "Auto-following %s\n",
				ref_name);

			path_list_insert(ref_name, &new_refs);

			rm = alloc_ref(strlen(ref_name) + 1);