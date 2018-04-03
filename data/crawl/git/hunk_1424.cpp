 		case RENAME_NORMAL:
 		case RENAME_ONE_FILE_TO_ONE:
 			clean_merge = merge_content(o, path,
-						    o_sha, o_mode, a_sha, a_mode, b_sha, b_mode,
+						    o_oid, o_mode, a_oid, a_mode, b_oid, b_mode,
 						    conflict_info);
 			break;
 		case RENAME_DELETE:
 			clean_merge = 0;
-			conflict_rename_delete(o, conflict_info->pair1,
-					       conflict_info->branch1,
-					       conflict_info->branch2);
+			if (conflict_rename_delete(o,
+						   conflict_info->pair1,
+						   conflict_info->branch1,
+						   conflict_info->branch2))
+				clean_merge = -1;
 			break;
 		case RENAME_ONE_FILE_TO_TWO:
 			clean_merge = 0;
-			conflict_rename_rename_1to2(o, conflict_info);
+			if (conflict_rename_rename_1to2(o, conflict_info))
+				clean_merge = -1;
 			break;
 		case RENAME_TWO_FILES_TO_ONE:
 			clean_merge = 0;
-			conflict_rename_rename_2to1(o, conflict_info);
+			if (conflict_rename_rename_2to1(o, conflict_info))
+				clean_merge = -1;
 			break;
 		default:
 			entry->processed = 0;
 			break;
 		}
-	} else if (o_sha && (!a_sha || !b_sha)) {
+	} else if (o_oid && (!a_oid || !b_oid)) {
 		/* Case A: Deleted in one */
-		if ((!a_sha && !b_sha) ||
-		    (!b_sha && blob_unchanged(o_sha, o_mode, a_sha, a_mode, normalize, path)) ||
-		    (!a_sha && blob_unchanged(o_sha, o_mode, b_sha, b_mode, normalize, path))) {
+		if ((!a_oid && !b_oid) ||
+		    (!b_oid && blob_unchanged(o, o_oid, o_mode, a_oid, a_mode, normalize, path)) ||
+		    (!a_oid && blob_unchanged(o, o_oid, o_mode, b_oid, b_mode, normalize, path))) {
 			/* Deleted in both or deleted in one and
 			 * unchanged in the other */
-			if (a_sha)
+			if (a_oid)
 				output(o, 2, _("Removing %s"), path);
 			/* do not touch working file if it did not exist */
-			remove_file(o, 1, path, !a_sha);
+			remove_file(o, 1, path, !a_oid);
 		} else {
 			/* Modify/delete; deleted side may have put a directory in the way */
 			clean_merge = 0;
-			handle_modify_delete(o, path, o_sha, o_mode,
-					     a_sha, a_mode, b_sha, b_mode);
+			if (handle_modify_delete(o, path, o_oid, o_mode,
+						 a_oid, a_mode, b_oid, b_mode))
+				clean_merge = -1;
 		}
-	} else if ((!o_sha && a_sha && !b_sha) ||
-		   (!o_sha && !a_sha && b_sha)) {
+	} else if ((!o_oid && a_oid && !b_oid) ||
+		   (!o_oid && !a_oid && b_oid)) {
 		/* Case B: Added in one. */
 		/* [nothing|directory] -> ([nothing|directory], file) */
 
 		const char *add_branch;
 		const char *other_branch;
 		unsigned mode;
-		const unsigned char *sha;
+		const struct object_id *oid;
 		const char *conf;
 
-		if (a_sha) {
+		if (a_oid) {
 			add_branch = o->branch1;
 			other_branch = o->branch2;
 			mode = a_mode;
-			sha = a_sha;
+			oid = a_oid;
 			conf = _("file/directory");
 		} else {
 			add_branch = o->branch2;
 			other_branch = o->branch1;
 			mode = b_mode;
-			sha = b_sha;
+			oid = b_oid;
 			conf = _("directory/file");
 		}
 		if (dir_in_way(path, !o->call_depth)) {
