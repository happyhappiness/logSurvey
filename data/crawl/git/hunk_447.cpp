 				  refs_heads_master, logmsg);
 }
 
-int ref_transaction_commit(struct ref_transaction *transaction,
-			   struct strbuf *err)
+int ref_transaction_prepare(struct ref_transaction *transaction,
+			    struct strbuf *err)
 {
 	struct ref_store *refs = transaction->ref_store;
 
 	switch (transaction->state) {
 	case REF_TRANSACTION_OPEN:
 		/* Good. */
 		break;
+	case REF_TRANSACTION_PREPARED:
+		die("BUG: prepare called twice on reference transaction");
+		break;
 	case REF_TRANSACTION_CLOSED:
 		die("BUG: prepare called on a closed reference transaction");
 		break;
