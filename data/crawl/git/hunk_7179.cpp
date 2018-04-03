 			store.value_regex = (regex_t*)xmalloc(sizeof(regex_t));
 			if (regcomp(store.value_regex, value_regex,
 					REG_EXTENDED)) {
-				fprintf(stderr, "Invalid pattern: %s\n",
-					value_regex);
+				error("invalid pattern: %s", value_regex);
 				free(store.value_regex);
 				ret = 6;
 				goto out_free;
