 				 * update_file_flags() instead of
 				 * update_file().
 				 */
-				update_file_flags(o,
-						  ren1->pair->two->sha1,
-						  ren1->pair->two->mode,
-						  ren1_dst,
-						  1, /* update_cache */
-						  0  /* update_wd    */);
-			} else if (!sha_eq(dst_other.sha1, null_sha1)) {
+				if (update_file_flags(o,
+						      &ren1->pair->two->oid,
+						      ren1->pair->two->mode,
+						      ren1_dst,
+						      1, /* update_cache */
+						      0  /* update_wd    */))
+					clean_merge = -1;
+			} else if (!oid_eq(&dst_other.oid, &null_oid)) {
 				clean_merge = 0;
 				try_merge = 1;
 				output(o, 1, _("CONFLICT (rename/add): Rename %s->%s in %s. "
