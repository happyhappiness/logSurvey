 		if (read_ref_full(entry->name, sha1, 0, &flags))
 			/* We should at least have found the packed ref. */
 			die("Internal error");
-		if ((flags & REF_ISSYMREF) || !(flags & REF_ISPACKED))
+		if ((flags & REF_ISSYMREF) || !(flags & REF_ISPACKED)) {
 			/*
 			 * This packed reference is overridden by a
 			 * loose reference, so it is OK that its value
