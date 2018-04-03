 	while (complete && cutoff <= complete->item->date) {
 		if (args->verbose)
 			fprintf(stderr, "Marking %s as complete\n",
-				sha1_to_hex(complete->item->object.sha1));
+				oid_to_hex(&complete->item->object.oid));
 		pop_most_recent_commit(&complete, COMPLETE);
 	}
 }
