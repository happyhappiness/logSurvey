 	return obj;
 }
 
+struct object *parse_object_or_die(const unsigned char *sha1,
+				   const char *name)
+{
+	struct object *o = parse_object(sha1);
+	if (o)
+		return o;
+
+	die(_("unable to parse object: %s"), name ? name : sha1_to_hex(sha1));
+}
+
 struct object *parse_object(const unsigned char *sha1)
 {
 	unsigned long size;
