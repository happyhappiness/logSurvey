 		return 0;
 	}
 	remote = make_remote(name, subkey - name);
-	if (!value) {
-		/* if we ever have a boolean variable, e.g. "remote.*.disabled"
-		 * [remote "frotz"]
-		 *      disabled
-		 * is a valid way to set it to true; we get NULL in value so
-		 * we need to handle it here.
-		 *
-		 * if (!strcmp(subkey, ".disabled")) {
-		 *      val = git_config_bool(key, value);
-		 *      return 0;
-		 * } else
-		 *
-		 */
-		return 0; /* ignore unknown booleans */
-	}
-	if (!strcmp(subkey, ".url")) {
-		add_url(remote, xstrdup(value));
+	if (!strcmp(subkey, ".mirror"))
+		remote->mirror = git_config_bool(key, value);
+	else if (!strcmp(subkey, ".skipdefaultupdate"))
+		remote->skip_default_update = git_config_bool(key, value);
+
+	else if (!strcmp(subkey, ".url")) {
+		const char *v;
+		if (git_config_string(&v, key, value))
+			return -1;
+		add_url(remote, v);
 	} else if (!strcmp(subkey, ".push")) {
-		add_push_refspec(remote, xstrdup(value));
+		const char *v;
+		if (git_config_string(&v, key, value))
+			return -1;
+		add_push_refspec(remote, v);
 	} else if (!strcmp(subkey, ".fetch")) {
-		add_fetch_refspec(remote, xstrdup(value));
+		const char *v;
+		if (git_config_string(&v, key, value))
+			return -1;
+		add_fetch_refspec(remote, v);
 	} else if (!strcmp(subkey, ".receivepack")) {
+		const char *v;
+		if (git_config_string(&v, key, value))
+			return -1;
 		if (!remote->receivepack)
-			remote->receivepack = xstrdup(value);
+			remote->receivepack = v;
 		else
 			error("more than one receivepack given, using the first");
 	} else if (!strcmp(subkey, ".uploadpack")) {
+		const char *v;
+		if (git_config_string(&v, key, value))
+			return -1;
 		if (!remote->uploadpack)
-			remote->uploadpack = xstrdup(value);
+			remote->uploadpack = v;
 		else
 			error("more than one uploadpack given, using the first");
 	} else if (!strcmp(subkey, ".tagopt")) {
 		if (!strcmp(value, "--no-tags"))
 			remote->fetch_tags = -1;
 	} else if (!strcmp(subkey, ".proxy")) {
-		remote->http_proxy = xstrdup(value);
-	} else if (!strcmp(subkey, ".skipdefaultupdate"))
-		remote->skip_default_update = 1;
+		return git_config_string((const char **)&remote->http_proxy,
+					 key, value);
+	}
 	return 0;
 }
 
