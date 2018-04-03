 	else if (!strcmp(arg, "strip"))
 		signed_tag_mode = STRIP;
 	else
-		return error("Unknown signed-tag mode: %s", arg);
+		return error("Unknown signed-tags mode: %s", arg);
 	return 0;
 }
 
