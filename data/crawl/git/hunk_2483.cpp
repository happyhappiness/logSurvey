 		fputs(find_unique_abbrev(get_object_hash(commit->object), revs->abbrev),
 		      stdout);
 	else
-		fputs(sha1_to_hex(commit->object.sha1), stdout);
+		fputs(oid_to_hex(&commit->object.oid), stdout);
 	if (revs->print_parents) {
 		struct commit_list *parents = commit->parents;
 		while (parents) {
-			printf(" %s", sha1_to_hex(parents->item->object.sha1));
+			printf(" %s", oid_to_hex(&parents->item->object.oid));
 			parents = parents->next;
 		}
 	}
