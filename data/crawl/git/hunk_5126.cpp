 	}
 	ret = ll_merge(&result, path, &base, NULL, &cur, "", &other, "", 0);
 	if (!ret) {
-		FILE *f = fopen(path, "w");
+		FILE *f;
+
+		if (utime(rerere_path(name, "postimage"), NULL) < 0)
+			warning("failed utime() on %s: %s",
+					rerere_path(name, "postimage"),
+					strerror(errno));
+		f = fopen(path, "w");
 		if (!f)
 			return error("Could not open %s: %s", path,
 				     strerror(errno));
