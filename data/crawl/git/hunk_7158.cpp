 			     o->merge_size);
 	if (a && old)
 		return o->gently ? -1 :
-			error("Entry '%s' overlaps with '%s'.  Cannot bind.", a->name, old->name);
+			error(ERRORMSG(o, bind_overlap), a->name, old->name);
 	if (!a)
 		return keep_entry(old, o);
 	else
