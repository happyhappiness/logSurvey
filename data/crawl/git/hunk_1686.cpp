 	struct object *obj, int msg_type, const char *message)
 {
 	if (msg_type == FSCK_WARN) {
-		warning("object %s: %s", oid_to_hex(&obj->oid), message);
+		warning("object %s: %s", describe_object(o, obj), message);
 		return 0;
 	}
-	error("object %s: %s", oid_to_hex(&obj->oid), message);
+	error("object %s: %s", describe_object(o, obj), message);
 	return 1;
 }
