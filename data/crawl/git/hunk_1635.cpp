 			safe_create_leading_directories_const(path);
 			unlink(path);
 			if (symlink(lnk, path))
-				ret = error_errno(_("failed to symlink '%s'"), path);
+				ret = err(o, _("failed to symlink '%s': %s"),
+					path, strerror(errno));
 			free(lnk);
 		} else
-			ret = error(_("do not know what to do with %06o %s '%s'"),
-				    mode, oid_to_hex(oid), path);
+			ret = err(o,
+				  _("do not know what to do with %06o %s '%s'"),
+				  mode, oid_to_hex(oid), path);
  free_buf:
 		free(buf);
 	}
  update_index:
 	if (!ret && update_cache)
-		add_cacheinfo(mode, oid, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
+		add_cacheinfo(o, mode, oid, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
 	return ret;
 }
 
