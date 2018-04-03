 		return;
 	}
 
-	buf = read_sha1_file(tag->object.sha1, &type, &size);
+	buf = read_sha1_file(get_object_hash(tag->object), &type, &size);
 	if (!buf)
 		die ("Could not read tag %s", sha1_to_hex(tag->object.sha1));
 	message = memmem(buf, size, "\n\n", 2);
