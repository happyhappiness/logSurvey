     hash_first(hash);
     while ((h = hash_next(hash))) {
 	fv = (fvdb_entry *) h;
-	storeAppendPrintf(e, "%9d %s\n", fv->n, fv->key);
+	storeAppendPrintf(e, "%9d %s\n", fv->n, hashKeyStr(&fv->hash));
     }
 }
 
