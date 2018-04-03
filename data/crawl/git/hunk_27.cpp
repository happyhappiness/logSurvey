 			continue;
 		default: /* OBJ_TAG (nested tags) is already handled */
 			warning("Tag points to object of unexpected type %s, skipping.",
-				typename(commit->object.type));
+				type_name(commit->object.type));
 			continue;
 		}
 
