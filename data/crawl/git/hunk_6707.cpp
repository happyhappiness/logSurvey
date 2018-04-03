 		if (strncmp(sanitized, work_tree, len) ||
 		    (sanitized[len] != '\0' && sanitized[len] != '/')) {
 		error_out:
-			error("'%s' is outside repository", orig);
-			free(sanitized);
-			return NULL;
+			die("'%s' is outside repository", orig);
 		}
 		if (sanitized[len] == '/')
 			len++;
