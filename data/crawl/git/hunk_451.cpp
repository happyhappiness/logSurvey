 
 	assert(err);
 
-	if (transaction->state != REF_TRANSACTION_OPEN)
-		die("BUG: commit called for transaction that is not open");
-
 	if (!transaction->nr)
 		goto cleanup;
 