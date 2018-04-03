 		error(_("some local refs could not be updated; try running\n"
 		      " 'git remote prune %s' to remove any old, conflicting "
 		      "branches"), remote_name);
+	strbuf_release(&note);
 	return rc;
 }
 