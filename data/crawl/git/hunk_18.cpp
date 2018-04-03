 	return show_ref(&atom->u.refname, ref->refname);
 }
 
+static void get_object(struct ref_array_item *ref, const struct object_id *oid,
+		       int deref, struct object **obj)
+{
+	int eaten;
+	unsigned long size;
+	void *buf = get_obj(oid, obj, &size, &eaten);
+	if (!buf)
+		die(_("missing object %s for %s"),
+		    oid_to_hex(oid), ref->refname);
+	if (!*obj)
+		die(_("parse_object_buffer failed on %s for %s"),
+		    oid_to_hex(oid), ref->refname);
+
+	grab_values(ref->value, deref, *obj, buf, size);
+	if (!eaten)
+		free(buf);
+}
+
 /*
  * Parse the object referred by ref, and grab needed value.
  */
 static void populate_value(struct ref_array_item *ref)
 {
-	void *buf;
 	struct object *obj;
-	int eaten, i;
-	unsigned long size;
+	int i;
 	const struct object_id *tagged;
 
 	ref->value = xcalloc(used_atom_cnt, sizeof(struct atom_value));
