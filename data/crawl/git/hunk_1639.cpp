 
 	if (code != 0) {
 		if (show(o, 4) || o->call_depth)
-			error(_("merging of trees %s and %s failed"),
+			err(o, _("merging of trees %s and %s failed"),
 			    oid_to_hex(&head->object.oid),
 			    oid_to_hex(&merge->object.oid));
 		return -1;
