 			free(entry);
 		else
 			*p = SET_PTR_TYPE(entry, type);
-		return;
+		return 0;
 	case PTR_TYPE_NOTE:
 		switch (type) {
 		case PTR_TYPE_NOTE:
 			if (!hashcmp(l->key_sha1, entry->key_sha1)) {
 				/* skip concatenation if l == entry */
 				if (!hashcmp(l->val_sha1, entry->val_sha1))
-					return;
+					return 0;
 
-				if (combine_notes(l->val_sha1, entry->val_sha1))
-					die("failed to combine notes %s and %s"
-					    " for object %s",
-					    sha1_to_hex(l->val_sha1),
-					    sha1_to_hex(entry->val_sha1),
-					    sha1_to_hex(l->key_sha1));
-
-				if (is_null_sha1(l->val_sha1))
+				ret = combine_notes(l->val_sha1,
+						    entry->val_sha1);
+				if (!ret && is_null_sha1(l->val_sha1))
 					note_tree_remove(t, tree, n, entry);
 				free(entry);
-				return;
+				return ret;
 			}
 			break;
 		case PTR_TYPE_SUBTREE:
