 	cd->del_count
     );
     storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n", 
-	on_count, bit_count,
-	xpercentInt(on_count, bit_count)
+	stats.bit_on_count, stats.bit_count,
+	xpercentInt(stats.bit_on_count, stats.bit_count)
+    );
+    storeAppendPrintf(e, "\t bit-seq: count: %d avg.len: %.2f\n", 
+	stats.bseq_count,
+	xdiv(stats.bseq_len_sum, stats.bseq_count)
     );
 }
 
