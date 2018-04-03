 	return ret;
 }
 
+int initial_ref_transaction_commit(struct ref_transaction *transaction,
+				   struct strbuf *err)
+{
+	int ret = 0, i;
+	int n = transaction->nr;
+	struct ref_update **updates = transaction->updates;
+
+	assert(err);
+
+	if (transaction->state != REF_TRANSACTION_OPEN)
+		die("BUG: commit called for transaction that is not open");
+
+	for (i = 0; i < n; i++) {
+		struct ref_update *update = updates[i];
+
+		if ((update->flags & REF_HAVE_OLD) &&
+		    !is_null_sha1(update->old_sha1))
+			die("BUG: initial ref transaction with old_sha1 set");
+	}
+
+	if (lock_packed_refs(0)) {
+		strbuf_addf(err, "unable to lock packed-refs file: %s",
+			    strerror(errno));
+		ret = TRANSACTION_GENERIC_ERROR;
+		goto cleanup;
+	}
+
+	for (i = 0; i < n; i++) {
+		struct ref_update *update = updates[i];
+
+		if ((update->flags & REF_HAVE_NEW) &&
+		    !is_null_sha1(update->new_sha1))
+			add_packed_ref(update->refname, update->new_sha1);
+	}
+
+	if (commit_packed_refs()) {
+		strbuf_addf(err, "unable to commit packed-refs file: %s",
+			    strerror(errno));
+		ret = TRANSACTION_GENERIC_ERROR;
+		goto cleanup;
+	}
+
+cleanup:
+	transaction->state = REF_TRANSACTION_CLOSED;
+	return ret;
+}
+
 char *shorten_unambiguous_ref(const char *refname, int strict)
 {
 	int i;
