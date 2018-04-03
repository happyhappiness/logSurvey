 			rs.src = ref->name;
 			rs.dst = NULL;
 			if (!remote_find_tracking(remote, &rs)) {
-				struct ref_lock *lock;
 				fprintf(stderr, " Also local %s\n", rs.dst);
 				if (will_delete_ref) {
 					if (delete_ref(rs.dst, NULL)) {
 						error("Failed to delete");
 					}
-				} else {
-					lock = lock_any_ref_for_update(rs.dst, NULL, 0);
-					if (!lock)
-						error("Failed to lock");
-					else
-						write_ref_sha1(lock, ref->new_sha1,
-							       "update by push");
-				}
+				} else
+					update_ref("update by push", rs.dst,
+						ref->new_sha1, NULL, 0, 0);
 				free(rs.dst);
 			}
 		}