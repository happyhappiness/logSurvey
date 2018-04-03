 
 	/* iterate over new parents */
 	for (i = 1; i < mergetag_data->argc; i++) {
-		unsigned char sha1[20];
-		if (get_sha1(mergetag_data->argv[i], sha1) < 0)
+		struct object_id oid;
+		if (get_sha1(mergetag_data->argv[i], oid.hash) < 0)
 			die(_("Not a valid object name: '%s'"), mergetag_data->argv[i]);
-		if (!hashcmp(tag->tagged->sha1, sha1))
+		if (!oidcmp(&tag->tagged->oid, &oid))
 			return; /* found */
 	}
 
