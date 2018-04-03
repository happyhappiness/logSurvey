 			result |= error(_("could not remove reference %s"), refname);
 	}
 
+out:
+	strbuf_release(&err);
 	return result;
 }
 