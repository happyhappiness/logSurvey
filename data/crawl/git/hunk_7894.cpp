 			 * A bisect set of size N has (N-1) commits further
 			 * to test, as we already know one bad one.
 			 */
-			cnt = all-reaches;
+			cnt = all - reaches;
 			if (cnt < reaches)
 				cnt = reaches;
+			strcpy(hex, sha1_to_hex(revs.commits->item->object.sha1));
+
+			if (bisect_find_all) {
+				traverse_commit_list(&revs, show_commit, show_object);
+				printf("------\n");
+			}
+
 			printf("bisect_rev=%s\n"
 			       "bisect_nr=%d\n"
 			       "bisect_good=%d\n"
 			       "bisect_bad=%d\n"
 			       "bisect_all=%d\n",
-			       sha1_to_hex(revs.commits->item->object.sha1),
+			       hex,
 			       cnt - 1,
 			       all - reaches - 1,
 			       reaches - 1,
