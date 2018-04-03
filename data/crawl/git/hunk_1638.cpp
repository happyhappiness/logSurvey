 		output(o, 1, _("CONFLICT (%s): Merge conflict in %s"),
 				reason, path);
 		if (rename_conflict_info && !df_conflict_remains)
-			if (update_stages(path, &one, &a, &b))
+			if (update_stages(o, path, &one, &a, &b))
 				return -1;
 	}
 
