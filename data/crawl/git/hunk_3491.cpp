 	if (mark_our_ref(refname, sha1, flag, NULL))
 		return 0;
 
-	if (capabilities)
-		packet_write(1, "%s %s%c%s%s%s agent=%s\n",
+	if (capabilities) {
+		struct strbuf symref_info = STRBUF_INIT;
+
+		format_symref_info(&symref_info, cb_data);
+		packet_write(1, "%s %s%c%s%s%s%s agent=%s\n",
 			     sha1_to_hex(sha1), refname_nons,
 			     0, capabilities,
 			     allow_tip_sha1_in_want ? " allow-tip-sha1-in-want" : "",
 			     stateless_rpc ? " no-done" : "",
+			     symref_info.buf,
 			     git_user_agent_sanitized());
-	else
+		strbuf_release(&symref_info);
+	} else {
 		packet_write(1, "%s %s\n", sha1_to_hex(sha1), refname_nons);
+	}
 	capabilities = NULL;
 	if (!peel_ref(refname, peeled))
 		packet_write(1, "%s %s^{}\n", sha1_to_hex(peeled), refname_nons);
 	return 0;
 }
 
+static int find_symref(const char *refname, const unsigned char *sha1, int flag,
+		       void *cb_data)
+{
+	const char *symref_target;
+	struct string_list_item *item;
+	unsigned char unused[20];
+
+	if ((flag & REF_ISSYMREF) == 0)
+		return 0;
+	symref_target = resolve_ref_unsafe(refname, unused, 0, &flag);
+	if (!symref_target || (flag & REF_ISSYMREF) == 0)
+		die("'%s' is a symref but it is not?", refname);
+	item = string_list_append(cb_data, refname);
+	item->util = xstrdup(symref_target);
+	return 0;
+}
+
 static void upload_pack(void)
 {
+	struct string_list symref = STRING_LIST_INIT_DUP;
+
+	head_ref_namespaced(find_symref, &symref);
+
 	if (advertise_refs || !stateless_rpc) {
 		reset_timeout();
-		head_ref_namespaced(send_ref, NULL);
-		for_each_namespaced_ref(send_ref, NULL);
+		head_ref_namespaced(send_ref, &symref);
+		for_each_namespaced_ref(send_ref, &symref);
 		packet_flush(1);
 	} else {
 		head_ref_namespaced(mark_our_ref, NULL);
 		for_each_namespaced_ref(mark_our_ref, NULL);
 	}
+	string_list_clear(&symref, 1);
 	if (advertise_refs)
 		return;
 