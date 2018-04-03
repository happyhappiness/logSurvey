				}
			}
			if (path) {
				path += repo->path_len;
				ls->dentry_name = xstrdup(path);
			}
		} else if (!strcmp(ctx->name, DAV_PROPFIND_COLLECTION)) {
			ls->dentry_flags |= IS_DIR;