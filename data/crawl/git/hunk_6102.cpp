 	const char *subkey = strrchr(name, '.');
 
 	if (!subkey)
-		return error("Config with no key for man viewer: %s", name);
+		return 0;
 
 	if (!strcmp(subkey, ".path")) {
 		if (!value)
