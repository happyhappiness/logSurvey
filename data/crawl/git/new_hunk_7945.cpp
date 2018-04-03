	return result;
}

void ref_remove_duplicates(struct ref *ref_map)
{
	struct ref **posn;
	struct ref *next;
	for (; ref_map; ref_map = ref_map->next) {
		if (!ref_map->peer_ref)
			continue;
		posn = &ref_map->next;
		while (*posn) {
			if ((*posn)->peer_ref &&
			    !strcmp((*posn)->peer_ref->name,
				    ref_map->peer_ref->name)) {
				if (strcmp((*posn)->name, ref_map->name))
					die("%s tracks both %s and %s",
					    ref_map->peer_ref->name,
					    (*posn)->name, ref_map->name);
				next = (*posn)->next;
				free((*posn)->peer_ref);
				free(*posn);
				*posn = next;
			} else {
				posn = &(*posn)->next;
			}
		}
	}
}

int remote_has_url(struct remote *remote, const char *url)
{
	int i;
