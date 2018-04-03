 		die_errno("Write to frontend failed");
 }
 
-static void cat_blob(struct object_entry *oe, unsigned char sha1[20])
+static void cat_blob(struct object_entry *oe, struct object_id *oid)
 {
 	struct strbuf line = STRBUF_INIT;
 	unsigned long size;
 	enum object_type type = 0;
 	char *buf;
 
 	if (!oe || oe->pack_id == MAX_PACK_ID) {
-		buf = read_sha1_file(sha1, &type, &size);
+		buf = read_sha1_file(oid->hash, &type, &size);
 	} else {
 		type = oe->type;
 		buf = gfi_unpack_entry(oe, &size);
