 	return;
     }
     if (table == (HashID) 0)
-	fatal_dump("storeUnChangeKey: Hash table 'table' is zero!\n");
+	fatal_dump("storeChangeKey: Hash table 'table' is zero!\n");
 
     if ((table_entry = hash_lookup(table, e->key)))
 	result = (StoreEntry *) table_entry;
