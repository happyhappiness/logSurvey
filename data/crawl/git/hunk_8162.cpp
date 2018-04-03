 		 */
 		if (idx_size != 4*256 + nr * 24 + 20 + 20) {
 			munmap(idx_map, idx_size);
-			return error("wrong index file size in %s", path);
+			return error("wrong index v1 file size in %s", path);
 		}
 	} else if (version == 2) {
 		/*
