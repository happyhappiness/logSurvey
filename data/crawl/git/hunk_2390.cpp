 		return;
 	}
 
-	buf = read_sha1_file(get_object_hash(tag->object), &type, &size);
+	buf = read_sha1_file(tag->object.oid.hash, &type, &size);
 	if (!buf)
 		die ("Could not read tag %s", oid_to_hex(&tag->object.oid));
 	message = memmem(buf, size, "\n\n", 2);
