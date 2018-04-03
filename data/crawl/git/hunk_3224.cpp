 				 update->old_sha1 : NULL),
 				&affected_refnames, NULL,
 				flags,
-				&update->type);
+				&update->type,
+				err);
 		if (!update->lock) {
 			ret = (errno == ENOTDIR)
 				? TRANSACTION_NAME_CONFLICT
 				: TRANSACTION_GENERIC_ERROR;
+			error("%s", err->buf);
+			strbuf_reset(err);
 			strbuf_addf(err, "Cannot lock the ref '%s'.",
 				    update->refname);
 			goto cleanup;
