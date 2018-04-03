 
 static int reject_merge(struct cache_entry *ce, struct unpack_trees_options *o)
 {
-	return error(ERRORMSG(o, would_overwrite), ce->name);
+	return error(ERRORMSG(o, ERROR_WOULD_OVERWRITE), ce->name);
 }
 
 static int same(struct cache_entry *a, struct cache_entry *b)
