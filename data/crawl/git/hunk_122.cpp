 
 	/* Preimage the patch was prepared for */
 	if (patch->is_new)
-		write_sha1_file("", 0, blob_type, pre_oid.hash);
+		write_object_file("", 0, blob_type, &pre_oid);
 	else if (get_oid(patch->old_sha1_prefix, &pre_oid) ||
 		 read_blob_object(&buf, &pre_oid, patch->old_mode))
 		return error(_("repository lacks the necessary blob to fall back on 3-way merge."));
