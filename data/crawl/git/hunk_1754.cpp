 				die_errno("readlink(%s)", name);
 			prep_temp_blob(name, temp, sb.buf, sb.len,
 				       (one->sha1_valid ?
-					one->sha1 : null_sha1),
+					one->oid.hash : null_sha1),
 				       (one->sha1_valid ?
 					one->mode : S_IFLNK));
 			strbuf_release(&sb);
