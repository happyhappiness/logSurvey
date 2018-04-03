 
 	if (show_keys) {
 		if (value_)
-			printf("%s ", key_);
+			printf("%s%c", key_, key_delim);
 		else
 			printf("%s", key_);
 	}
