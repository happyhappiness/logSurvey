     LOCAL_ARRAY(char, where, 100);
 
     where[0] = '\0';
-    if (entry->swap_file_number >= 0)
-	storeAppendPrintf(entry, "D%d", entry->swap_file_number);
-    if (entry->swap_status == SWAPPING_OUT)
-	strncat(where, "/SWAP-OUT", sizeof(where));
-    if (entry->swap_status == SWAP_OK)
-	strncat(where, "/SWAP-OK", sizeof(where));
-    else
-	strncat(where, "/NO-SWAP", sizeof(where));
-
-    if (entry->mem_status == SWAPPING_IN)
-	strncat(where, "/SWAP-IN", sizeof(where));
-    else if (entry->mem_status == IN_MEMORY)
-	strncat(where, "/IN-MEM", sizeof(where));
-    else			/* STORE_PENDING */
-	strncat(where, "/OUT-MEM", sizeof(where));
+    sprintf (where, "D%d/%s/%s",
+	entry->swap_file_number,
+	swapStatusStr[entry->swap_status],
+	memStatusStr[entry->mem_status]);
     return (where);
 }
 
