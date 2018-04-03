 				return 0;
 			if (!state->force)
 				return error("%s is a directory", path.buf);
-			remove_subtree(path.buf);
+			remove_subtree(&path);
 		} else if (unlink(path.buf))
 			return error("unable to unlink old '%s' (%s)",
 				     path.buf, strerror(errno));