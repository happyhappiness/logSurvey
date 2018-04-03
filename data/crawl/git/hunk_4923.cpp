 		}
 		if (fd < 0) {
 			free(new);
-			return error("git checkout-index: unable to create file %s (%s)",
+			return error("unable to create file %s (%s)",
 				path, strerror(errno));
 		}
 
