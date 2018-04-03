 		die("%s: not a valid old SHA1", oldval);
 
 	if (delete)
-		return delete_ref(refname, oldval ? oldsha1 : NULL);
+		return delete_ref(refname, oldval ? oldsha1 : NULL, 0);
 	else
 		return update_ref(msg, refname, sha1, oldval ? oldsha1 : NULL,
 				  no_deref ? REF_NODEREF : 0, DIE_ON_ERR);
