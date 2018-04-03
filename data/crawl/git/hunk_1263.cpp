 			const char *err)
 {
 	fprintf(stderr, "%s in %s %s: %s\n",
-		msg_type, typename(obj->type), oid_to_hex(&obj->oid), err);
+		msg_type, typename(obj->type), describe_object(obj), err);
 }
 
 static int objerror(struct object *obj, const char *err)
