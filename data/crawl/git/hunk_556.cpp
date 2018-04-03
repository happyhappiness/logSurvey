 	} cleanup_mode;
 };
 
-static void create_tag(const unsigned char *object, const char *tag,
+static void create_tag(const struct object_id *object, const char *tag,
 		       struct strbuf *buf, struct create_tag_options *opt,
-		       unsigned char *prev, unsigned char *result)
+		       struct object_id *prev, struct object_id *result)
 {
 	enum object_type type;
 	struct strbuf header = STRBUF_INIT;
 	char *path = NULL;
 
-	type = sha1_object_info(object, NULL);
+	type = sha1_object_info(object->hash, NULL);
 	if (type <= OBJ_NONE)
 	    die(_("bad object type."));
 
