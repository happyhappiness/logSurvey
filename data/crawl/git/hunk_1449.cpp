 			goto finish;
 		}
 
-		if (get_sha1_hex(sb.buf + GIT_SHA1_HEXSZ + 1, to_obj)) {
+		if (get_oid_hex(sb.buf + GIT_SHA1_HEXSZ + 1, &to_obj)) {
 			ret = error(invalid_line, sb.buf);
 			goto finish;
 		}
 
-		if (copy_note_for_rewrite(c, from_obj, to_obj))
+		if (copy_note_for_rewrite(c, from_obj.hash, to_obj.hash))
 			ret = error(_("Failed to copy notes from '%s' to '%s'"),
-					sha1_to_hex(from_obj), sha1_to_hex(to_obj));
+					oid_to_hex(&from_obj), oid_to_hex(&to_obj));
 	}
 
 finish:
