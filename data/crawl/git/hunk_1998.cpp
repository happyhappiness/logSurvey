 			break;
 	}
 
-	if (id->collection->status_nr <= id->variant)
-		return error("no remembered resolution for '%s'", path);
+	if (id->collection->status_nr <= id->variant) {
+		error("no remembered resolution for '%s'", path);
+		goto fail_exit;
+	}
 
 	filename = rerere_path(id, "postimage");
-	if (unlink(filename))
-		return (errno == ENOENT
-			? error("no remembered resolution for %s", path)
-			: error("cannot unlink %s: %s", filename, strerror(errno)));
+	if (unlink(filename)) {
+		if (errno == ENOENT)
+			error("no remembered resolution for %s", path);
+		else
+			error("cannot unlink %s: %s", filename, strerror(errno));
+		goto fail_exit;
+	};
 
 	/*
 	 * Update the preimage so that the user can resolve the
