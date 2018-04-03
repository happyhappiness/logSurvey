	for (; ref_map; ref_map = ref_map->next)
		if (ref_map->peer_ref && !strcmp(current_branch->refname,
					ref_map->peer_ref->name))
			die("Refusing to fetch into current branch %s "
			    "of non-bare repository", current_branch->refname);
}

static int do_fetch(struct transport *transport,
