			die("Could not get fetch map for refspec %s",
				states->remote->fetch_refspec[i]);

	states->new.strdup_strings = states->tracked.strdup_strings = 1;
	for (ref = fetch_map; ref; ref = ref->next) {
		struct string_list *target = &states->tracked;
		unsigned char sha1[20];
		void *util = NULL;

