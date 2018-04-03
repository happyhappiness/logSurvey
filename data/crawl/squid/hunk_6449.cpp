     storeAppendPrintf(e, "\t deletion attempts: %d\n",
 	cd->del_count
 	);
-    storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n",
+    storeAppendPrintf(e, "\t bits: per entry: %d on: %d capacity: %d util: %d%%\n",
+	cd->bits_per_entry,
 	stats.bit_on_count, stats.bit_count,
 	xpercentInt(stats.bit_on_count, stats.bit_count)
 	);
