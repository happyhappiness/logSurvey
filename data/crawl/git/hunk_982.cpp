 			oid_to_hex(&parent->object.oid));
 
 	if (get_message(commit, &msg) != 0)
-		return error(_("Cannot get commit message for %s"),
+		return error(_("cannot get commit message for %s"),
 			oid_to_hex(&commit->object.oid));
 
 	/*
