 	BIT_SET(e->flag, RELEASE_REQUEST);
 	return -1;
     }
-    debug(5, "storeRelease: Releasing: %s\n", e->url);
+    debug(0, 5, "storeRelease: Releasing: %s\n", e->url);
 
     if (table == (HashID) 0)
 	return -1;
 
     if (e->key == NULL) {
-	debug(0, "storeRelease: NULL key for %s\n", e->url);
-	debug(0, "Dump of Entry 'e':\n %s\n", storeToString(e));
+	debug(0, 0, "storeRelease: NULL key for %s\n", e->url);
+	debug(0, 0, "Dump of Entry 'e':\n %s\n", storeToString(e));
 	fatal_dump(NULL);
     }
     if ((hptr = hash_lookup(table, e->key)) == NULL) {
-	debug(0, "storeRelease: Not Found: %s\n", e->url);
-	debug(0, "Dump of Entry 'e':\n %s\n", storeToString(e));
+	debug(0, 0, "storeRelease: Not Found: %s\n", e->url);
+	debug(0, 0, "Dump of Entry 'e':\n %s\n", storeToString(e));
 	fatal_dump(NULL);
     }
     result = (StoreEntry *) hptr;
 
     if (result != e) {
-	debug(0, "storeRelease: Duplicated entry? <URL:%s>\n",
+	debug(0, 0, "storeRelease: Duplicated entry? <URL:%s>\n",
 	    result->url ? result->url : "NULL");
-	debug(0, "Dump of Entry 'e':\n%s", storeToString(e));
-	debug(0, "Dump of Entry 'result':\n%s", storeToString(result));
+	debug(0, 0, "Dump of Entry 'e':\n%s", storeToString(e));
+	debug(0, 0, "Dump of Entry 'result':\n%s", storeToString(result));
 	fatal_dump(NULL);
     }
     if (e->type_id == REQUEST_OP_GET) {
