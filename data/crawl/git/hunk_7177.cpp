 		/* Leave the extended basename untouched.. */
 		if (!dot || i > store.baselen) {
 			if (!iskeychar(c) || (i == store.baselen+1 && !isalpha(c))) {
-				fprintf(stderr, "invalid key: %s\n", key);
+				error("invalid key: %s", key);
 				free(store.key);
 				ret = 1;
 				goto out_free;
 			}
 			c = tolower(c);
 		} else if (c == '\n') {
-			fprintf(stderr, "invalid key (newline): %s\n", key);
+			error("invalid key (newline): %s", key);
 			free(store.key);
 			ret = 1;
 			goto out_free;
