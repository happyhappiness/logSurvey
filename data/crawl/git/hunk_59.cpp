 			goto out;
 		}
 		if (check_sha1_signature(expected_sha1, *contents,
-					 *size, typename(*type))) {
+					 *size, type_name(*type))) {
 			error("sha1 mismatch for %s (expected %s)", path,
 			      sha1_to_hex(expected_sha1));
 			free(*contents);
