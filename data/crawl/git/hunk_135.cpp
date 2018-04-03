 			return error_errno("readlink(\"%s\")", path);
 		if (!(flags & HASH_WRITE_OBJECT))
 			hash_object_file(sb.buf, sb.len, blob_type, oid);
-		else if (write_sha1_file(sb.buf, sb.len, blob_type, oid->hash))
+		else if (write_object_file(sb.buf, sb.len, blob_type, oid))
 			rc = error("%s: failed to insert into database", path);
 		strbuf_release(&sb);
 		break;