 		    ? "Unable to add %s to database"
 		    : "Unable to hash %s", path);
 	printf("%s\n", sha1_to_hex(sha1));
+	maybe_flush_or_die(stdout, "hash to stdout");
 }
 
 static void hash_stdin(const char *type, int write_object)
