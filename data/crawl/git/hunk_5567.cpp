 	return 0;
 }
 
+static int mark_our_ref(const char *refname, const unsigned char *sha1, int flag, void *cb_data)
+{
+	struct object *o = parse_object(sha1);
+	if (!o)
+		die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
+	if (!(o->flags & OUR_REF)) {
+		o->flags |= OUR_REF;
+		nr_our_refs++;
+	}
+	return 0;
+}
+
 static void upload_pack(void)
 {
-	reset_timeout();
-	head_ref(send_ref, NULL);
-	for_each_ref(send_ref, NULL);
-	packet_flush(1);
+	if (advertise_refs || !stateless_rpc) {
+		reset_timeout();
+		head_ref(send_ref, NULL);
+		for_each_ref(send_ref, NULL);
+		packet_flush(1);
+	} else {
+		head_ref(mark_our_ref, NULL);
+		for_each_ref(mark_our_ref, NULL);
+	}
+	if (advertise_refs)
+		return;
+
 	receive_needs();
 	if (want_obj.nr) {
 		get_common_commits();
