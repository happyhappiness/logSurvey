 			else
 				mode = 0666;
 			fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, mode);
-			if (fd < 0)
-				die_errno(_("failed to open '%s'"), path);
+			if (fd < 0) {
+				ret = err(o, _("failed to open '%s': %s"),
+					  path, strerror(errno));
+				goto free_buf;
+			}
 			write_in_full(fd, buf, size);
 			close(fd);
 		} else if (S_ISLNK(mode)) {
 			char *lnk = xmemdupz(buf, size);
 			safe_create_leading_directories_const(path);
 			unlink(path);
 			if (symlink(lnk, path))
-				die_errno(_("failed to symlink '%s'"), path);
+				ret = err(o, _("failed to symlink '%s': %s"),
+					path, strerror(errno));
 			free(lnk);
 		} else
-			die(_("do not know what to do with %06o %s '%s'"),
-			    mode, sha1_to_hex(sha), path);
+			ret = err(o,
+				  _("do not know what to do with %06o %s '%s'"),
+				  mode, oid_to_hex(oid), path);
+ free_buf:
 		free(buf);
 	}
  update_index:
-	if (update_cache)
-		add_cacheinfo(mode, sha, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
+	if (!ret && update_cache)
+		add_cacheinfo(o, mode, oid, path, 0, update_wd, ADD_CACHE_OK_TO_ADD);
+	return ret;
 }
 
-static void update_file(struct merge_options *o,
-			int clean,
-			const unsigned char *sha,
-			unsigned mode,
-			const char *path)
+static int update_file(struct merge_options *o,
+		       int clean,
+		       const struct object_id *oid,
+		       unsigned mode,
+		       const char *path)
 {
-	update_file_flags(o, sha, mode, path, o->call_depth || clean, !o->call_depth);
+	return update_file_flags(o, oid, mode, path, o->call_depth || clean, !o->call_depth);
 }
 
 /* Low level file merging, update and removal */
 
 struct merge_file_info {
-	unsigned char sha[20];
+	struct object_id oid;
 	unsigned mode;
 	unsigned clean:1,
 		 merge:1;
