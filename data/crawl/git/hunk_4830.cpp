 			system_wide = git_etc_gitconfig();
 	}
 
-	key = xstrdup(key_);
-	for (tl=key+strlen(key)-1; tl >= key && *tl != '.'; --tl)
-		*tl = tolower(*tl);
-	for (tl=key; *tl && *tl != '.'; ++tl)
-		*tl = tolower(*tl);
-
 	if (use_key_regexp) {
+		char *tl;
+
+		/*
+		 * NEEDSWORK: this naive pattern lowercasing obviously does not
+		 * work for more complex patterns like "^[^.]*Foo.*bar".
+		 * Perhaps we should deprecate this altogether someday.
+		 */
+
+		key = xstrdup(key_);
+		for (tl = key + strlen(key) - 1;
+		     tl >= key && *tl != '.';
+		     tl--)
+			*tl = tolower(*tl);
+		for (tl = key; *tl && *tl != '.'; tl++)
+			*tl = tolower(*tl);
+
 		key_regexp = (regex_t*)xmalloc(sizeof(regex_t));
 		if (regcomp(key_regexp, key, REG_EXTENDED)) {
 			fprintf(stderr, "Invalid key pattern: %s\n", key_);
+			free(key);
 			goto free_strings;
 		}
+	} else {
+		if (git_config_parse_key(key_, &key, NULL))
+			goto free_strings;
 	}
 
 	if (regex_) {
