 		const unsigned char *sha1;
 		struct object *o;
 
-		for (i = 0; i < revs->num_ignore_packed; i++) {
-			if (matches_pack_name(p, revs->ignore_packed[i]))
-				break;
-		}
-		if (revs->num_ignore_packed <= i)
+		if (!p->pack_local || p->pack_keep)
 			continue;
 		if (open_pack_index(p))
 			die("cannot open pack index");
