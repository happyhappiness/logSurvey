 				new_path = unique_path(ren1_dst, branch2);
 				output(1, "Added as %s instead", new_path);
 				update_file(0, dst_other.sha1, dst_other.mode, new_path);
-			} else if ((item = path_list_lookup(ren1_dst, renames2Dst))) {
+			} else if ((item = string_list_lookup(ren1_dst, renames2Dst))) {
 				ren2 = item->util;
 				clean_merge = 0;
 				ren2->processed = 1;
