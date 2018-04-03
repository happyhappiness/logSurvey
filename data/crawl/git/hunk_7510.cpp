 		return error("Cannot do a bind merge of %d trees\n",
 			     o->merge_size);
 	if (a && old)
-		die("Entry '%s' overlaps.  Cannot bind.", a->name);
+		return error("Entry '%s' overlaps.  Cannot bind.", a->name);
 	if (!a)
 		return keep_entry(old, o);
 	else