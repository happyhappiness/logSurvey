
void ref_remove_duplicates(struct ref *ref_map)
{
	struct string_list refs = { NULL, 0, 0, 0 };
	struct string_list_item *item = NULL;
	struct ref *prev = NULL, *next = NULL;
	for (; ref_map; prev = ref_map, ref_map = next) {
		next = ref_map->next;
		if (!ref_map->peer_ref)
			continue;

		item = string_list_lookup(ref_map->peer_ref->name, &refs);
		if (item) {
			if (strcmp(((struct ref *)item->util)->name,
				   ref_map->name))
				die("%s tracks both %s and %s",
				    ref_map->peer_ref->name,
				    ((struct ref *)item->util)->name,
				    ref_map->name);
			prev->next = ref_map->next;
			free(ref_map->peer_ref);
			free(ref_map);
		}

		item = string_list_insert(ref_map->peer_ref->name, &refs);
		item->util = ref_map;
	}
	string_list_clear(&refs, 0);
}

int remote_has_url(struct remote *remote, const char *url)