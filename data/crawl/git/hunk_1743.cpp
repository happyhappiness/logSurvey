 				       ren1_dst, branch2);
 				if (o->call_depth) {
 					struct merge_file_info mfi;
-					mfi = merge_file_one(o, ren1_dst, null_sha1, 0,
-							 ren1->pair->two->oid.hash,
+					mfi = merge_file_one(o, ren1_dst, &null_oid, 0,
+							 &ren1->pair->two->oid,
 							 ren1->pair->two->mode,
-							 dst_other.oid.hash,
+							 &dst_other.oid,
 							 dst_other.mode,
 							 branch1, branch2);
 					output(o, 1, _("Adding merged %s"), ren1_dst);
-					update_file(o, 0, mfi.oid.hash,
+					update_file(o, 0, &mfi.oid,
 						    mfi.mode, ren1_dst);
 					try_merge = 0;
 				} else {
 					char *new_path = unique_path(o, ren1_dst, branch2);
 					output(o, 1, _("Adding as %s instead"), new_path);
-					update_file(o, 0, dst_other.oid.hash,
+					update_file(o, 0, &dst_other.oid,
 						    dst_other.mode, new_path);
 					free(new_path);
 				}
