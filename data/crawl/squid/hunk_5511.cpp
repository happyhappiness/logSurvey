 	delay_data[pool].class3->individual[position] -= qty;
 	return;
     }
-    fatalf("delayBytesWanted: Invalid class %d\n", class);
+    fatalf("delayBytesWanted: Invalid class %d\n", delay_class);
     assert(0);
 }
 
