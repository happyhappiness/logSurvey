 	for (i = 0; i < req_nr; i++)
 		if (!(refs.objects[i].item->flags & SHOWN)) {
 			if (++ret == 1)
-				error(message);
+				error("%s", message);
 			error("%s %s", sha1_to_hex(refs.objects[i].item->sha1),
 				refs.objects[i].name);
 		}
