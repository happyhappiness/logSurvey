 		if (!commit) {
 			warning("%s: Unexpected object of type %s, skipping.",
 				e->name,
-				typename(e->item->type));
+				type_name(e->item->type));
 			continue;
 		}
 
