 			logerror("'%s': Non-absolute path denied (base-path active)", dir);
 			return NULL;
 		}
-		snprintf(rpath, PATH_MAX, "%s%s", base_path, dir);
+		rlen = snprintf(rpath, sizeof(rpath), "%s%s", base_path, dir);
+		if (rlen >= sizeof(rpath)) {
+			logerror("base-path too large: %s", rpath);
+			return NULL;
+		}
 		dir = rpath;
 	}
 