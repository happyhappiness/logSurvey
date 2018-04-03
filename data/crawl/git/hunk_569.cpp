 			if (!tree_content_remove(orig_root, fullpath, &leaf, 0))
 				die("Failed to remove path %s", fullpath);
 			tree_content_set(orig_root, realpath,
-				leaf.versions[1].oid.hash,
+				&leaf.versions[1].oid,
 				leaf.versions[1].mode,
 				leaf.tree);
 		} else if (S_ISDIR(e->versions[1].mode)) {
 			/* This is a subdir that may contain note entries */
 			num_notes += do_change_note_fanout(orig_root, e,
-				hex_sha1, tmp_hex_sha1_len,
+				hex_oid, tmp_hex_oid_len,
 				fullpath, tmp_fullpath_len, fanout);
 		}
 
