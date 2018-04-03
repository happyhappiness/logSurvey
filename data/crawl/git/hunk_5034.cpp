 		return -1;
 
 	if (warn_ambiguous_refs && refs_found > 1)
-		fprintf(stderr, warning, len, str);
+		warning(warn_msg, len, str);
 
 	if (reflog_len) {
 		int nth, i;
