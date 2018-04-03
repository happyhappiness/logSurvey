		fputs(find_unique_abbrev(get_object_hash(commit->object), revs->abbrev),
		      stdout);
	else
		fputs(oid_to_hex(&commit->object.oid), stdout);
	if (revs->print_parents) {
		struct commit_list *parents = commit->parents;
		while (parents) {
			printf(" %s", oid_to_hex(&parents->item->object.oid));
			parents = parents->next;
		}
	}
