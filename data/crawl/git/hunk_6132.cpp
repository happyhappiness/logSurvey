 			baa = 1;
 		}
 	}
-	for (ent = sb->ent; ent; ent = ent->next) {
-		/* Mark the ones that haven't been checked */
-		if (0 < ent->suspect->refcnt)
-			ent->suspect->refcnt = -ent->suspect->refcnt;
-	}
-	for (ent = sb->ent; ent; ent = ent->next) {
-		/*
-		 * ... then pick each and see if they have the the
-		 * correct refcnt.
-		 */
-		int found;
-		struct blame_entry *e;
-		struct origin *suspect = ent->suspect;
-
-		if (0 < suspect->refcnt)
-			continue;
-		suspect->refcnt = -suspect->refcnt; /* Unmark */
-		for (found = 0, e = sb->ent; e; e = e->next) {
-			if (e->suspect != suspect)
-				continue;
-			found++;
-		}
-		if (suspect->refcnt != found) {
-			fprintf(stderr, "%s in %s has refcnt %d, not %d\n",
-				ent->suspect->path,
-				sha1_to_hex(ent->suspect->commit->object.sha1),
-				ent->suspect->refcnt, found);
-			baa = 2;
-		}
-	}
 	if (baa) {
 		int opt = 0160;
 		find_alignment(sb, &opt);
