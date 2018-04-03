 				l->key_sha1[19] = (unsigned char) len;
 				type = PTR_TYPE_SUBTREE;
 			}
-			note_tree_insert(t, node, n, l, type,
-					 combine_notes_concatenate);
+			if (note_tree_insert(t, node, n, l, type,
+					     combine_notes_concatenate))
+				die("Failed to load %s %s into notes tree "
+				    "from %s",
+				    type == PTR_TYPE_NOTE ? "note" : "subtree",
+				    sha1_to_hex(l->key_sha1), t->ref);
 		}
 		continue;
 
