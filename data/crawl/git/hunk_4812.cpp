 			 * it may have been deleted since the index
 			 * was loaded!
 			 */
-			if (p->pack_fd == -1 && open_packed_git(p)) {
+			if (!is_pack_valid(p)) {
 				error("packfile %s cannot be accessed", p->pack_name);
 				goto next;
 			}