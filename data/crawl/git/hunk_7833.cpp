 		if (write_ref_sha1(lock, new_sha1, "push")) {
 			return "failed to write"; /* error() already called */
 		}
-		fprintf(stderr, "%s: %s -> %s\n", name,
-			sha1_to_hex(old_sha1), sha1_to_hex(new_sha1));
 		return NULL; /* good */
 	}
 }