 				}
 			}
 			if (path) {
-				path += repo->path_len;
-				ls->dentry_name = xstrdup(path);
+				const char *url = repo->url;
+				if (repo->path)
+					url = repo->path;
+				if (strncmp(path, url, repo->path_len))
+					error("Parsed path '%s' does not match url: '%s'\n",
+					      path, url);
+				else {
+					path += repo->path_len;
+					ls->dentry_name = xstrdup(path);
+				}
 			}
 		} else if (!strcmp(ctx->name, DAV_PROPFIND_COLLECTION)) {
 			ls->dentry_flags |= IS_DIR;