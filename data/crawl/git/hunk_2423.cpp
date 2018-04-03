 		if (o->verbosity >= 4)
 			printf("No merge base found; doing history-less merge\n");
 	} else if (!bases->next) {
-		base_sha1 = get_object_hash(bases->item->object);
-		base_tree_sha1 = get_object_hash(bases->item->tree->object);
+		base_sha1 = bases->item->object.oid.hash;
+		base_tree_sha1 = bases->item->tree->object.oid.hash;
 		if (o->verbosity >= 4)
 			printf("One merge base found (%.7s)\n",
 				sha1_to_hex(base_sha1));
 	} else {
 		/* TODO: How to handle multiple merge-bases? */
-		base_sha1 = get_object_hash(bases->item->object);
-		base_tree_sha1 = get_object_hash(bases->item->tree->object);
+		base_sha1 = bases->item->object.oid.hash;
+		base_tree_sha1 = bases->item->tree->object.oid.hash;
 		if (o->verbosity >= 3)
 			printf("Multiple merge bases found. Using the first "
 				"(%.7s)\n", sha1_to_hex(base_sha1));
