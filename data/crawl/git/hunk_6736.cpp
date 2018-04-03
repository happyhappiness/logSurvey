 		/* This reads lines formatted in one of three formats:
 		 *
 		 * (1) mode         SP sha1          TAB path
-		 * The first format is what "git-apply --index-info"
+		 * The first format is what "git apply --index-info"
 		 * reports, and used to reconstruct a partial tree
 		 * that is used for phony merge base tree when falling
 		 * back on 3-way merge.
 		 *
 		 * (2) mode SP type SP sha1          TAB path
-		 * The second format is to stuff git-ls-tree output
+		 * The second format is to stuff "git ls-tree" output
 		 * into the index file.
 		 *
 		 * (3) mode         SP sha1 SP stage TAB path
 		 * This format is to put higher order stages into the
-		 * index file and matches git-ls-files --stage output.
+		 * index file and matches "git ls-files --stage" output.
 		 */
 		errno = 0;
 		ul = strtoul(buf.buf, &ptr, 8);