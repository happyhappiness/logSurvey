		if (o->verbosity >= 4)
			printf("No merge base found; doing history-less merge\n");
	} else if (!bases->next) {
		base_sha1 = bases->item->object.sha1;
		base_tree_sha1 = bases->item->tree->object.sha1;
		if (o->verbosity >= 4)
			printf("One merge base found (%.7s)\n",
				sha1_to_hex(base_sha1));
	} else {
		/* TODO: How to handle multiple merge-bases? */
		base_sha1 = bases->item->object.sha1;
		base_tree_sha1 = bases->item->tree->object.sha1;
		if (o->verbosity >= 3)
			printf("Multiple merge bases found. Using the first "
				"(%.7s)\n", sha1_to_hex(base_sha1));