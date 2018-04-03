 		}
 	}
 
+	if (backend_data->packed_transaction &&
+	    ref_transaction_abort(backend_data->packed_transaction, &err)) {
+		error("error aborting transaction: %s", err.buf);
+		strbuf_release(&err);
+	}
+
+	if (backend_data->packed_refs_locked)
+		packed_refs_unlock(refs->packed_ref_store);
+
+	free(backend_data);
+
 	transaction->state = REF_TRANSACTION_CLOSED;
 }
 
