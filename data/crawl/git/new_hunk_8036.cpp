	}
	return 0;
}

static struct ref *get_expanded_map(struct ref *remote_refs,
				    const struct refspec *refspec)
{
	struct ref *ref;
	struct ref *ret = NULL;
	struct ref **tail = &ret;

	int remote_prefix_len = strlen(refspec->src);
	int local_prefix_len = strlen(refspec->dst);

	for (ref = remote_refs; ref; ref = ref->next) {
		if (strchr(ref->name, '^'))
			continue; /* a dereference item */
		if (!prefixcmp(ref->name, refspec->src)) {
			char *match;
			struct ref *cpy = copy_ref(ref);
			match = ref->name + remote_prefix_len;

			cpy->peer_ref = alloc_ref(local_prefix_len +
						  strlen(match) + 1);
			sprintf(cpy->peer_ref->name, "%s%s",
				refspec->dst, match);
			if (refspec->force)
				cpy->peer_ref->force = 1;
			*tail = cpy;
			tail = &cpy->next;
		}
	}

	return ret;
}

static struct ref *find_ref_by_name_abbrev(struct ref *refs, const char *name)
{
	struct ref *ref;
	for (ref = refs; ref; ref = ref->next) {
		if (ref_matches_abbrev(name, ref->name))
			return ref;
	}
	return NULL;
}

struct ref *get_remote_ref(struct ref *remote_refs, const char *name)
{
	struct ref *ref = find_ref_by_name_abbrev(remote_refs, name);

	if (!ref)
		die("Couldn't find remote ref %s\n", name);

	return copy_ref(ref);
}

static struct ref *get_local_ref(const char *name)
{
	struct ref *ret;
	if (!name)
		return NULL;

	if (!prefixcmp(name, "refs/")) {
		ret = alloc_ref(strlen(name) + 1);
		strcpy(ret->name, name);
		return ret;
	}

	if (!prefixcmp(name, "heads/") ||
	    !prefixcmp(name, "tags/") ||
	    !prefixcmp(name, "remotes/")) {
		ret = alloc_ref(strlen(name) + 6);
		sprintf(ret->name, "refs/%s", name);
		return ret;
	}

	ret = alloc_ref(strlen(name) + 12);
	sprintf(ret->name, "refs/heads/%s", name);
	return ret;
}

int get_fetch_map(struct ref *remote_refs,
		  const struct refspec *refspec,
		  struct ref ***tail)
{
	struct ref *ref_map, *rm;

	if (refspec->pattern) {
		ref_map = get_expanded_map(remote_refs, refspec);
	} else {
		ref_map = get_remote_ref(remote_refs,
					 refspec->src[0] ?
					 refspec->src : "HEAD");

		ref_map->peer_ref = get_local_ref(refspec->dst);

		if (refspec->force)
			ref_map->peer_ref->force = 1;
	}

	for (rm = ref_map; rm; rm = rm->next) {
		if (rm->peer_ref && check_ref_format(rm->peer_ref->name + 5))
			die("* refusing to create funny ref '%s' locally",
			    rm->peer_ref->name);
	}

	tail_link_ref(ref_map, tail);

	return 0;
}
