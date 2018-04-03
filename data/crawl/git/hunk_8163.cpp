 			max_size += (nr - 1)*8;
 		if (idx_size < min_size || idx_size > max_size) {
 			munmap(idx_map, idx_size);
-			return error("wrong index file size in %s", path);
+			return error("wrong index v2 file size in %s", path);
 		}
 		if (idx_size != min_size) {
 			/* make sure we can deal with large pack offsets */