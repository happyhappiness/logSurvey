 	}
 }
 
+static void *get_base_data(struct base_data *c)
+{
+	if (!c->data) {
+		struct object_entry *obj = c->obj;
+
+		if (obj->type == OBJ_REF_DELTA || obj->type == OBJ_OFS_DELTA) {
+			void *base = get_base_data(c->base);
+			void *raw = get_data_from_pack(obj);
+			c->data = patch_delta(
+				base, c->base->size,
+				raw, obj->size,
+				&c->size);
+			free(raw);
+			if (!c->data)
+				bad_object(obj->idx.offset, "failed to apply delta");
+		} else
+			c->data = get_data_from_pack(obj);
+
+		base_cache_used += c->size;
+		prune_base_data(c);
+	}
+	return c->data;
+}
+
 static void resolve_delta(struct object_entry *delta_obj,
 			  struct base_data *base_obj, enum object_type type)
 {
