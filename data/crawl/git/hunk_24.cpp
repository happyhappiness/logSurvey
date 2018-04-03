 		buf = read_sha1_file(oid->hash, &type, &size);
 		if (!buf)
 			die ("Could not read blob %s", oid_to_hex(oid));
-		if (check_sha1_signature(oid->hash, buf, size, typename(type)) < 0)
+		if (check_sha1_signature(oid->hash, buf, size, type_name(type)) < 0)
 			die("sha1 mismatch in blob %s", oid_to_hex(oid));
 		object = parse_object_buffer(oid, type, size, buf, &eaten);
 	}
