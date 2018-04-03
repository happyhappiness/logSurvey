 	die("pack has bad object at offset %lu: %s", offset, buf);
 }
 
+static void prune_base_data(struct base_data *retain)
+{
+	struct base_data *b = base_cache;
+	for (b = base_cache;
+	     base_cache_used > delta_base_cache_limit && b;
+	     b = b->child) {
+		if (b->data && b != retain) {
+			free(b->data);
+			b->data = NULL;
+			base_cache_used -= b->size;
+		}
+	}
+}
+
 static void link_base_data(struct base_data *base, struct base_data *c)
 {
 	if (base)
