 		return DIFF_COMMIT;
 	if (!strcasecmp(var+ofs, "whitespace"))
 		return DIFF_WHITESPACE;
+	if (!strcasecmp(var+ofs, "func"))
+		return DIFF_FUNCINFO;
 	die("bad config variable '%s'", var);
 }
 
