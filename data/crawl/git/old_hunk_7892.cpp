
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
		if (ref_map->peer_ref && refspec->force)
			ref_map->peer_ref->force = 1;
	}

	for (rm = ref_map; rm; rm = rm->next) {
