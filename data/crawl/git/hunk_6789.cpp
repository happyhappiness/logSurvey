 	case S_IFREG:
 		new = read_blob_entry(ce, path, &size);
 		if (!new)
-			return error("git-checkout-index: unable to read sha1 file of %s (%s)",
+			return error("git checkout-index: unable to read sha1 file of %s (%s)",
 				path, sha1_to_hex(ce->sha1));
 
 		/*
