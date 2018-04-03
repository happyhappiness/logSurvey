 	enum object_type type;
 
 	if (!name)
-		return 1;
+		return 0;
 	if (get_sha1(name, sha1) < 0)
-		return 1;
+		return 0;
 
 	buf = read_sha1_file(sha1, &type, &size);
 	if (!buf)
-		return 1;
+		return error("unable to read mailmap object at %s", name);
 	if (type != OBJ_BLOB)
-		return 1;
+		return error("mailmap is not a blob: %s", name);
 
 	read_mailmap_buf(map, buf, size, repo_abbrev);
 
