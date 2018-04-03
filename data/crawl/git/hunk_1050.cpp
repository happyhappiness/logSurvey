 	/* our_oid is ours */
 	if (patch->is_new) {
 		if (load_current(state, &tmp_image, patch))
-			return error("cannot read the current contents of '%s'",
+			return error(_("cannot read the current contents of '%s'"),
 				     patch->new_name);
 	} else {
 		if (load_preimage(state, &tmp_image, patch, st, ce))
-			return error("cannot read the current contents of '%s'",
+			return error(_("cannot read the current contents of '%s'"),
 				     patch->old_name);
 	}
 	write_sha1_file(tmp_image.buf, tmp_image.len, blob_type, our_oid.hash);
