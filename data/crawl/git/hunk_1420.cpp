 				       ren1_dst, branch2);
 				if (o->call_depth) {
 					struct merge_file_info mfi;
-					mfi = merge_file_one(o, ren1_dst, null_sha1, 0,
-							 ren1->pair->two->sha1, ren1->pair->two->mode,
-							 dst_other.sha1, dst_other.mode,
-							 branch1, branch2);
+					if (merge_file_one(o, ren1_dst, &null_oid, 0,
+							   &ren1->pair->two->oid,
+							   ren1->pair->two->mode,
+							   &dst_other.oid,
+							   dst_other.mode,
+							   branch1, branch2, &mfi)) {
+						clean_merge = -1;
+						goto cleanup_and_return;
+					}
 					output(o, 1, _("Adding merged %s"), ren1_dst);
-					update_file(o, 0, mfi.sha, mfi.mode, ren1_dst);
+					if (update_file(o, 0, &mfi.oid,
+							mfi.mode, ren1_dst))
+						clean_merge = -1;
 					try_merge = 0;
 				} else {
 					char *new_path = unique_path(o, ren1_dst, branch2);
 					output(o, 1, _("Adding as %s instead"), new_path);
-					update_file(o, 0, dst_other.sha1, dst_other.mode, new_path);
+					if (update_file(o, 0, &dst_other.oid,
+							dst_other.mode, new_path))
+						clean_merge = -1;
 					free(new_path);
 				}
 			} else
 				try_merge = 1;
 
+			if (clean_merge < 0)
+				goto cleanup_and_return;
 			if (try_merge) {
 				struct diff_filespec *one, *a, *b;
 				src_other.path = (char *)ren1_src;
