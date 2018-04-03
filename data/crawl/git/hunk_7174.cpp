 	case KEY_SEEN:
 		if (matches(key, value)) {
 			if (store.seen == 1 && store.multi_replace == 0) {
-				fprintf(stderr,
-					"Warning: %s has multiple values\n",
-					key);
+				warning("%s has multiple values", key);
 			} else if (store.seen >= MAX_MATCHES) {
-				fprintf(stderr, "Too many matches\n");
+				error("too many matches for %s", key);
 				return 1;
 			}
 
