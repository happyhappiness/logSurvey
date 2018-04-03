 			return error(_("cannot read the current contents of '%s'"),
 				     patch->old_name);
 	}
-	write_sha1_file(tmp_image.buf, tmp_image.len, blob_type, our_oid.hash);
+	write_object_file(tmp_image.buf, tmp_image.len, blob_type, &our_oid);
 	clear_image(&tmp_image);
 
 	/* in-core three-way merge between post and our using pre as base */
