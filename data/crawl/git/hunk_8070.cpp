 		/* See if the old one matches what the patch
 		 * applies to.
 		 */
-		hash_sha1_file(desc->buffer, desc->size, blob_type, sha1);
+		hash_sha1_file(buf->buf, buf->len, blob_type, sha1);
 		if (strcmp(sha1_to_hex(sha1), patch->old_sha1_prefix))
 			return error("the patch applies to '%s' (%s), "
 				     "which does not match the "
