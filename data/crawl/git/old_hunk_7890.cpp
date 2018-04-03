			 * as given in branch.<name>.remote, we add the
			 * ref given in branch.<name>.merge, too.
			 */
			if (has_merge && !strcmp(branch->remote_name,
						remote->name))
				add_merge_config(&ref_map, remote_refs, branch, &tail);
		} else {
			ref_map = get_remote_ref(remote_refs, "HEAD");
			ref_map->merge = 1;
		}
	}
