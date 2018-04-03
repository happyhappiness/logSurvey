 	}
 }
 
-static int add_cacheinfo(unsigned int mode, const struct object_id *oid,
+static int add_cacheinfo(struct merge_options *o,
+		unsigned int mode, const struct object_id *oid,
 		const char *path, int stage, int refresh, int options)
 {
 	struct cache_entry *ce;
 	int ret;
 
 	ce = make_cache_entry(mode, oid ? oid->hash : null_sha1, path, stage, 0);
 	if (!ce)
-		return error(_("addinfo_cache failed for path '%s'"), path);
+		return err(o, _("addinfo_cache failed for path '%s'"), path);
 
 	ret = add_cache_entry(ce, options);
 	if (refresh) {
