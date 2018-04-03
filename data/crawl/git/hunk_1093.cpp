 	status = finish_object_disambiguation(&ds, sha1);
 
 	if (!quietly && (status == SHORT_NAME_AMBIGUOUS))
-		return error("short SHA1 %.*s is ambiguous.", ds.len, ds.hex_pfx);
+		return error("short SHA1 %s is ambiguous.", ds.hex_pfx);
 	return status;
 }
 