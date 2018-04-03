 		if ((dir = opendir(name)) == NULL) {
 			if (errno == ENOENT)
 				continue;
-			error("cannot opendir %s (%s)", name, strerror(errno));
+			error_errno("cannot opendir %s", name);
 			goto out;
 		}
 
