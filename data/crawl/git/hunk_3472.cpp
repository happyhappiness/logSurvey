 		if (matches(key, value)) {
 			if (store.seen == 1 && store.multi_replace == 0) {
 				warning("%s has multiple values", key);
-			} else if (store.seen >= MAX_MATCHES) {
-				error("too many matches for %s", key);
-				return 1;
 			}
 
+			ALLOC_GROW(store.offset, store.seen + 1,
+				   store.offset_alloc);
+
 			store.offset[store.seen] = cf->do_ftell(cf);
 			store.seen++;
 		}
