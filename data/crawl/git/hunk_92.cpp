 {
 	struct stat buf;
 	if (stat(path, &buf)) {
-		die_errno("failed to stat '%*s%s%s'",
+		die_errno(_("failed to stat '%*s%s%s'"),
 				prefix_len,
 				prefix ? prefix : "",
 				prefix ? "/" : "", path);
