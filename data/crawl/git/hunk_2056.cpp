 			ret = symlink(new, path);
 			free(new);
 			if (ret)
-				return error("unable to create symlink %s (%s)",
-					     path, strerror(errno));
+				return error_errno("unable to create symlink %s",
+						   path);
 			break;
 		}
 
