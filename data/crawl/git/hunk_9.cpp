 			die(_("Could not get fetch map for refspec %s"),
 				states->remote->fetch_refspec[i]);
 
-	states->new.strdup_strings = 1;
+	states->new_refs.strdup_strings = 1;
 	states->tracked.strdup_strings = 1;
 	states->stale.strdup_strings = 1;
 	for (ref = fetch_map; ref; ref = ref->next) {
 		if (!ref->peer_ref || !ref_exists(ref->peer_ref->name))
-			string_list_append(&states->new, abbrev_branch(ref->name));
+			string_list_append(&states->new_refs, abbrev_branch(ref->name));
 		else
 			string_list_append(&states->tracked, abbrev_branch(ref->name));
 	}
