 				       "%s added in %s",
 				       ren1_src, ren1_dst, branch1,
 				       ren1_dst, branch2);
-				new_path = unique_path(o, ren1_dst, branch2);
-				output(o, 1, "Adding as %s instead", new_path);
-				update_file(o, 0, dst_other.sha1, dst_other.mode, new_path);
+				if (o->call_depth) {
+					struct merge_file_info mfi;
+					struct diff_filespec one, a, b;
+
+					one.path = a.path = b.path =
+						(char *)ren1_dst;
+					hashcpy(one.sha1, null_sha1);
+					one.mode = 0;
+					hashcpy(a.sha1, ren1->pair->two->sha1);
+					a.mode = ren1->pair->two->mode;
+					hashcpy(b.sha1, dst_other.sha1);
+					b.mode = dst_other.mode;
+					mfi = merge_file(o, &one, &a, &b,
+							 branch1,
+							 branch2);
+					output(o, 1, "Adding merged %s", ren1_dst);
+					update_file(o, 0,
+						    mfi.sha,
+						    mfi.mode,
+						    ren1_dst);
+				} else {
+					new_path = unique_path(o, ren1_dst, branch2);
+					output(o, 1, "Adding as %s instead", new_path);
+					update_file(o, 0, dst_other.sha1, dst_other.mode, new_path);
+				}
 			} else if ((item = string_list_lookup(ren1_dst, renames2Dst))) {
 				ren2 = item->util;
 				clean_merge = 0;
