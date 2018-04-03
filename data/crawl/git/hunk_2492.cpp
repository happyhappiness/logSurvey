 		ret = read_sha1_file(get_object_hash(commit->object), &type, &size);
 		if (!ret)
 			die("cannot read commit object %s",
-			    sha1_to_hex(commit->object.sha1));
+			    oid_to_hex(&commit->object.oid));
 		if (type != OBJ_COMMIT)
 			die("expected commit for %s, got %s",
-			    sha1_to_hex(commit->object.sha1), typename(type));
+			    oid_to_hex(&commit->object.oid), typename(type));
 		if (sizep)
 			*sizep = size;
 	}
