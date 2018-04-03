 static int packed_delete_refs(struct ref_store *ref_store, const char *msg,
 			     struct string_list *refnames, unsigned int flags)
 {
-	die("BUG: not implemented yet");
+	struct packed_ref_store *refs =
+		packed_downcast(ref_store, REF_STORE_WRITE, "delete_refs");
+	struct strbuf err = STRBUF_INIT;
+	struct ref_transaction *transaction;
+	struct string_list_item *item;
+	int ret;
+
+	(void)refs; /* We need the check above, but don't use the variable */
+
+	if (!refnames->nr)
+		return 0;
+
+	/*
+	 * Since we don't check the references' old_oids, the
+	 * individual updates can't fail, so we can pack all of the
+	 * updates into a single transaction.
+	 */
+
+	transaction = ref_store_transaction_begin(ref_store, &err);
+	if (!transaction)
+		return -1;
+
+	for_each_string_list_item(item, refnames) {
+		if (ref_transaction_delete(transaction, item->string, NULL,
+					   flags, msg, &err)) {
+			warning(_("could not delete reference %s: %s"),
+				item->string, err.buf);
+			strbuf_reset(&err);
+		}
+	}
+
+	ret = ref_transaction_commit(transaction, &err);
+
+	if (ret) {
+		if (refnames->nr == 1)
+			error(_("could not delete reference %s: %s"),
+			      refnames->items[0].string, err.buf);
+		else
+			error(_("could not delete references: %s"), err.buf);
+	}
+
+	ref_transaction_free(transaction);
+	strbuf_release(&err);
+	return ret;
 }
 
 static int packed_pack_refs(struct ref_store *ref_store, unsigned int flags)