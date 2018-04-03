 		}
 		if (ref_transaction_delete(transaction,
 					   namespaced_name,
-					   old_oid ? old_oid->hash : NULL,
+					   old_oid,
 					   0, "push", &err)) {
 			rp_error("%s", err.buf);
 			strbuf_release(&err);
