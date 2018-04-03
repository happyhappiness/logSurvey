		const char *name = abbrev_branch(refspec.src);
		/* symbolic refs pointing nowhere were handled already */
		if ((flags & REF_ISSYMREF) ||
				unsorted_string_list_has_string(&states->tracked,
					name) ||
				unsorted_string_list_has_string(&states->new,
					name))
			return 0;
		item = string_list_append(name, &states->stale);
		item->util = xstrdup(refname);
	}
	return 0;
}

static int get_ref_states(const struct ref *ref, struct ref_states *states)
{
	struct ref *fetch_map = NULL, **tail = &fetch_map;
	int i;

	for (i = 0; i < states->remote->fetch_refspec_nr; i++)
		if (get_fetch_map(ref, states->remote->fetch + i, &tail, 1))
			die("Could not get fetch map for refspec %s",
				states->remote->fetch_refspec[i]);

	states->new.strdup_strings = states->tracked.strdup_strings = 1;
	for (ref = fetch_map; ref; ref = ref->next) {
		struct string_list *target = &states->tracked;
		unsigned char sha1[20];
		void *util = NULL;

		if (!ref->peer_ref || read_ref(ref->peer_ref->name, sha1))
			target = &states->new;
		else {
			target = &states->tracked;
			if (hashcmp(sha1, ref->new_sha1))
				util = &states;
		}
		string_list_append(abbrev_branch(ref->name), target)->util = util;
	}
	free_refs(fetch_map);

	for_each_ref(handle_one_branch, states);
	sort_string_list(&states->stale);

	return 0;
}

struct known_remote {
	struct known_remote *next;
	struct remote *remote;
