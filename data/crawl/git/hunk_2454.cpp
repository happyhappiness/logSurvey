 	}
 	if (tagged->type == OBJ_TREE) {
 		warning("Omitting tag %s,\nsince tags of trees (or tags of tags of trees, etc.) are not supported.",
-			sha1_to_hex(tag->object.sha1));
+			oid_to_hex(&tag->object.oid));
 		return;
 	}
 
 	buf = read_sha1_file(get_object_hash(tag->object), &type, &size);
 	if (!buf)
-		die ("Could not read tag %s", sha1_to_hex(tag->object.sha1));
+		die ("Could not read tag %s", oid_to_hex(&tag->object.oid));
 	message = memmem(buf, size, "\n\n", 2);
 	if (message) {
 		message += 2;
