 		output(o, 1, _("CONFLICT (%s): Merge conflict in %s"),
 				reason, path);
 		if (rename_conflict_info && !df_conflict_remains)
-			update_stages(path, &one, &a, &b);
+			if (update_stages(o, path, &one, &a, &b))
+				return -1;
 	}
 
 	if (df_conflict_remains) {
 		char *new_path;
 		if (o->call_depth) {
 			remove_file_from_cache(path);
 		} else {
-			if (!mfi.clean)
-				update_stages(path, &one, &a, &b);
-			else {
+			if (!mfi.clean) {
+				if (update_stages(o, path, &one, &a, &b))
+					return -1;
+			} else {
 				int file_from_stage2 = was_tracked(path);
 				struct diff_filespec merged;
-				hashcpy(merged.sha1, mfi.sha);
+				oidcpy(&merged.oid, &mfi.oid);
 				merged.mode = mfi.mode;
 
-				update_stages(path, NULL,
-					      file_from_stage2 ? &merged : NULL,
-					      file_from_stage2 ? NULL : &merged);
+				if (update_stages(o, path, NULL,
+						  file_from_stage2 ? &merged : NULL,
+						  file_from_stage2 ? NULL : &merged))
+					return -1;
 			}
 
 		}
 		new_path = unique_path(o, path, rename_conflict_info->branch1);
 		output(o, 1, _("Adding as %s instead"), new_path);
-		update_file(o, 0, mfi.sha, mfi.mode, new_path);
+		if (update_file(o, 0, &mfi.oid, mfi.mode, new_path)) {
+			free(new_path);
+			return -1;
+		}
 		free(new_path);
 		mfi.clean = 0;
-	} else {
-		update_file(o, mfi.clean, mfi.sha, mfi.mode, path);
-	}
+	} else if (update_file(o, mfi.clean, &mfi.oid, mfi.mode, path))
+		return -1;
 	return mfi.clean;
-
 }
 
 /* Per entry merge function */
