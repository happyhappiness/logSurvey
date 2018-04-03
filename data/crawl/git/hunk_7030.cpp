 		if (args.verbose)
 			fprintf(stderr, "updating local tracking ref '%s'\n", rs.dst);
 		if (ref->deletion) {
-			if (delete_ref(rs.dst, NULL))
-				error("Failed to delete");
+			delete_ref(rs.dst, NULL);
 		} else
 			update_ref("update by push", rs.dst,
 					ref->new_sha1, NULL, 0, 0);
