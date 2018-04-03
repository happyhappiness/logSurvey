 		    int literally)
 {
 	struct stat st;
-	unsigned char sha1[20];
+	struct object_id oid;
 
 	if (fstat(fd, &st) < 0 ||
 	    (literally
-	     ? hash_literally(sha1, fd, type, flags)
-	     : index_fd(sha1, fd, &st, type_from_string(type), path, flags)))
+	     ? hash_literally(&oid, fd, type, flags)
+	     : index_fd(oid.hash, fd, &st, type_from_string(type), path, flags)))
 		die((flags & HASH_WRITE_OBJECT)
 		    ? "Unable to add %s to database"
 		    : "Unable to hash %s", path);
-	printf("%s\n", sha1_to_hex(sha1));
+	printf("%s\n", oid_to_hex(&oid));
 	maybe_flush_or_die(stdout, "hash to stdout");
 }
 