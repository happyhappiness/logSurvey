 		return error("Cannot do a bind merge of %d trees\n",
 			     o->merge_size);
 	if (a && old)
-		return error("Entry '%s' overlaps.  Cannot bind.", a->name);
+		return o->gently ? -1 :
+			error("Entry '%s' overlaps.  Cannot bind.", a->name);
 	if (!a)
 		return keep_entry(old, o);
 	else
