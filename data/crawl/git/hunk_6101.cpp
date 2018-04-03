 	}
 	subkey = strrchr(name, '.');
 	if (!subkey)
-		return error("Config with no key for remote %s", name);
+		return 0;
 	remote = make_remote(name, subkey - name);
 	remote->origin = REMOTE_CONFIG;
 	if (!strcmp(subkey, ".mirror"))