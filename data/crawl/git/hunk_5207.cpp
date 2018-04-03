 	if (read_cache() < 0)
 		die("git %s: failed to read the index", me);
 
-	return do_pick_commit();
+	prepare_revs(&revs);
+
+	while ((commit = get_revision(&revs))) {
+		int res = do_pick_commit();
+		if (res)
+			return res;
+	}
+
+	return 0;
 }
 
 int cmd_revert(int argc, const char **argv, const char *prefix)