 		 */
 		hash_sha1_file(img->buf, img->len, blob_type, oid.hash);
 		if (strcmp(oid_to_hex(&oid), patch->old_sha1_prefix))
-			return error("the patch applies to '%s' (%s), "
-				     "which does not match the "
-				     "current contents.",
+			return error(_("the patch applies to '%s' (%s), "
+				       "which does not match the "
+				       "current contents."),
 				     name, oid_to_hex(&oid));
 	}
 	else {
 		/* Otherwise, the old one must be empty. */
 		if (img->len)
-			return error("the patch applies to an empty "
-				     "'%s' but it is not empty", name);
+			return error(_("the patch applies to an empty "
+				       "'%s' but it is not empty"), name);
 	}
 
 	get_oid_hex(patch->new_sha1_prefix, &oid);
