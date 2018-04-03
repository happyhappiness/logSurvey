 		}
 
 		if (type == OBJ_BLOB)
-			return stream_blob_to_fd(1, sha1, NULL, 0);
-		buf = read_sha1_file(sha1, &type, &size);
+			return stream_blob_to_fd(1, oid.hash, NULL, 0);
+		buf = read_sha1_file(oid.hash, &type, &size);
 		if (!buf)
 			die("Cannot read object %s", obj_name);
 
