 		const char *name = abbrev_branch(refspec.src);
 		/* symbolic refs pointing nowhere were handled already */
 		if ((flags & REF_ISSYMREF) ||
-				unsorted_string_list_has_string(&states->tracked,
-					name) ||
-				unsorted_string_list_has_string(&states->new,
-					name))
+		    string_list_has_string(&states->tracked, name) ||
+		    string_list_has_string(&states->new, name))
 			return 0;
 		item = string_list_append(name, &states->stale);
 		item->util = xstrdup(refname);
 	}
 	return 0;
 }
 
-static int get_ref_states(const struct ref *ref, struct ref_states *states)
+static int get_ref_states(const struct ref *remote_refs, struct ref_states *states)
 {
 	struct ref *fetch_map = NULL, **tail = &fetch_map;
+	struct ref *ref;
 	int i;
 
 	for (i = 0; i < states->remote->fetch_refspec_nr; i++)
-		if (get_fetch_map(ref, states->remote->fetch + i, &tail, 1))
+		if (get_fetch_map(remote_refs, states->remote->fetch + i, &tail, 1))
 			die("Could not get fetch map for refspec %s",
 				states->remote->fetch_refspec[i]);
 
 	states->new.strdup_strings = states->tracked.strdup_strings = 1;
 	for (ref = fetch_map; ref; ref = ref->next) {
-		struct string_list *target = &states->tracked;
 		unsigned char sha1[20];
-		void *util = NULL;
-
 		if (!ref->peer_ref || read_ref(ref->peer_ref->name, sha1))
-			target = &states->new;
-		else {
-			target = &states->tracked;
-			if (hashcmp(sha1, ref->new_sha1))
-				util = &states;
-		}
-		string_list_append(abbrev_branch(ref->name), target)->util = util;
+			string_list_append(abbrev_branch(ref->name), &states->new);
+		else
+			string_list_append(abbrev_branch(ref->name), &states->tracked);
 	}
 	free_refs(fetch_map);
 
+	sort_string_list(&states->new);
+	sort_string_list(&states->tracked);
 	for_each_ref(handle_one_branch, states);
 	sort_string_list(&states->stale);
 
 	return 0;
 }
 
+struct push_info {
+	char *dest;
+	int forced;
+	enum {
+		PUSH_STATUS_CREATE = 0,
+		PUSH_STATUS_DELETE,
+		PUSH_STATUS_UPTODATE,
+		PUSH_STATUS_FASTFORWARD,
+		PUSH_STATUS_OUTOFDATE,
+		PUSH_STATUS_NOTQUERIED,
+	} status;
+};
+
+static int get_push_ref_states(const struct ref *remote_refs,
+	struct ref_states *states)
+{
+	struct remote *remote = states->remote;
+	struct ref *ref, *local_refs, *push_map, **push_tail;
+	if (remote->mirror)
+		return 0;
+
+	local_refs = get_local_heads();
+	ref = push_map = copy_ref_list(remote_refs);
+	while (ref->next)
+		ref = ref->next;
+	push_tail = &ref->next;
+
+	match_refs(local_refs, push_map, &push_tail, remote->push_refspec_nr,
+		   remote->push_refspec, MATCH_REFS_NONE);
+
+	states->push.strdup_strings = 1;
+	for (ref = push_map; ref; ref = ref->next) {
+		struct string_list_item *item;
+		struct push_info *info;
+
+		if (!ref->peer_ref)
+			continue;
+		hashcpy(ref->new_sha1, ref->peer_ref->new_sha1);
+
+		item = string_list_append(abbrev_branch(ref->peer_ref->name),
+					  &states->push);
+		item->util = xcalloc(sizeof(struct push_info), 1);
+		info = item->util;
+		info->forced = ref->force;
+		info->dest = xstrdup(abbrev_branch(ref->name));
+
+		if (is_null_sha1(ref->new_sha1)) {
+			info->status = PUSH_STATUS_DELETE;
+		} else if (!hashcmp(ref->old_sha1, ref->new_sha1))
+			info->status = PUSH_STATUS_UPTODATE;
+		else if (is_null_sha1(ref->old_sha1))
+			info->status = PUSH_STATUS_CREATE;
+		else if (has_sha1_file(ref->old_sha1) &&
+			 ref_newer(ref->new_sha1, ref->old_sha1))
+			info->status = PUSH_STATUS_FASTFORWARD;
+		else
+			info->status = PUSH_STATUS_OUTOFDATE;
+	}
+	free_refs(local_refs);
+	free_refs(push_map);
+	return 0;
+}
+
+static int get_push_ref_states_noquery(struct ref_states *states)
+{
+	int i;
+	struct remote *remote = states->remote;
+	struct string_list_item *item;
+	struct push_info *info;
+
+	if (remote->mirror)
+		return 0;
+
+	states->push.strdup_strings = 1;
+	if (!remote->push_refspec_nr) {
+		item = string_list_append("(matching)", &states->push);
+		info = item->util = xcalloc(sizeof(struct push_info), 1);
+		info->status = PUSH_STATUS_NOTQUERIED;
+		info->dest = xstrdup(item->string);
+	}
+	for (i = 0; i < remote->push_refspec_nr; i++) {
+		struct refspec *spec = remote->push + i;
+		if (spec->matching)
+			item = string_list_append("(matching)", &states->push);
+		else if (strlen(spec->src))
+			item = string_list_append(spec->src, &states->push);
+		else
+			item = string_list_append("(delete)", &states->push);
+
+		info = item->util = xcalloc(sizeof(struct push_info), 1);
+		info->forced = spec->force;
+		info->status = PUSH_STATUS_NOTQUERIED;
+		info->dest = xstrdup(spec->dst ? spec->dst : item->string);
+	}
+	return 0;
+}
+
+static int get_head_names(const struct ref *remote_refs, struct ref_states *states)
+{
+	struct ref *ref, *matches;
+	struct ref *fetch_map = NULL, **fetch_map_tail = &fetch_map;
+	struct refspec refspec;
+
+	refspec.force = 0;
+	refspec.pattern = 1;
+	refspec.src = refspec.dst = "refs/heads/*";
+	states->heads.strdup_strings = 1;
+	get_fetch_map(remote_refs, &refspec, &fetch_map_tail, 0);
+	matches = guess_remote_head(find_ref_by_name(remote_refs, "HEAD"),
+				    fetch_map, 1);
+	for(ref = matches; ref; ref = ref->next)
+		string_list_append(abbrev_branch(ref->name), &states->heads);
+
+	free_refs(fetch_map);
+	free_refs(matches);
+
+	return 0;
+}
+
 struct known_remote {
 	struct known_remote *next;
 	struct remote *remote;
