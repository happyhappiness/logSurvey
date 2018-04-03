 				fd = create_file(path, 0666);
 			if (fd < 0) {
 				free(new);
-				return error("git-checkout-index: unable to create "
+				return error("git checkout-index: unable to create "
 						 "file %s (%s)", path, strerror(errno));
 			}
 			wrote = write_in_full(fd, new, size);
 			close(fd);
 			free(new);
 			if (wrote != size)
-				return error("git-checkout-index: unable to write file %s",
+				return error("git checkout-index: unable to write file %s",
 					path);
 		} else {
 			wrote = symlink(new, path);
 			free(new);
 			if (wrote)
-				return error("git-checkout-index: unable to create "
+				return error("git checkout-index: unable to create "
 						 "symlink %s (%s)", path, strerror(errno));
 		}
 		break;
 	case S_IFGITLINK:
 		if (to_tempfile)
-			return error("git-checkout-index: cannot create temporary subproject %s", path);
+			return error("git checkout-index: cannot create temporary subproject %s", path);
 		if (mkdir(path, 0777) < 0)
-			return error("git-checkout-index: cannot create subproject directory %s", path);
+			return error("git checkout-index: cannot create subproject directory %s", path);
 		break;
 	default:
-		return error("git-checkout-index: unknown file mode for %s", path);
+		return error("git checkout-index: unknown file mode for %s", path);
 	}
 
 	if (state->refresh_cache) {
