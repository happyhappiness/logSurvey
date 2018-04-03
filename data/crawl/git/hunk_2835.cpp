 		if (!dot || i > baselen) {
 			if (!iskeychar(c) ||
 			    (i == baselen + 1 && !isalpha(c))) {
-				error("invalid key: %s", key);
+				if (!quiet)
+					error("invalid key: %s", key);
 				goto out_free_ret_1;
 			}
 			c = tolower(c);
 		} else if (c == '\n') {
-			error("invalid key (newline): %s", key);
+			if (!quiet)
+				error("invalid key (newline): %s", key);
 			goto out_free_ret_1;
 		}
-		(*store_key)[i] = c;
+		if (store_key)
+			(*store_key)[i] = c;
 	}
-	(*store_key)[i] = 0;
+	if (store_key)
+		(*store_key)[i] = 0;
 
 	return 0;
 
 out_free_ret_1:
-	free(*store_key);
-	*store_key = NULL;
+	if (store_key) {
+		free(*store_key);
+		*store_key = NULL;
+	}
 	return -CONFIG_INVALID_KEY;
 }
 
+int git_config_parse_key(const char *key, char **store_key, int *baselen)
+{
+	return git_config_parse_key_1(key, store_key, baselen, 0);
+}
+
+int git_config_key_is_valid(const char *key)
+{
+	return !git_config_parse_key_1(key, NULL, NULL, 1);
+}
+
 /*
  * If value==NULL, unset in (remove from) config,
  * if value_regex!=NULL, disregard key/value pairs where value does not match.
