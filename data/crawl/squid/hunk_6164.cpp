 void
 delayBytesIn(delay_id d, int qty)
 {
-    int position = d & 0xFFFF;
-    unsigned char class = (d & 0xFF0000) >> 16;
-    if (class == 0)
+    unsigned short position = d & 0xFFFF;
+    unsigned short pool = (d >> 16) - 1;
+    unsigned char class;
+
+    if (pool == 0xFFFF)
 	return;
-    if (class == 1) {
-	delay_data.class1_aggregate -= qty;
+    class = Config.Delay.class[pool];
+    switch (class) {
+    case 1:
+	delay_data[pool].class1->aggregate -= qty;
 	return;
-    }
-    if (class == 2) {
-	delay_data.class2_aggregate -= qty;
-	delay_data.class2_individual[position] -= qty;
+    case 2:
+	delay_data[pool].class2->aggregate -= qty;
+	delay_data[pool].class2->individual[position] -= qty;
 	return;
-    }
-    if (class == 3) {
-	delay_data.class3_aggregate -= qty;
-	delay_data.class3_network[position >> 8] -= qty;
-	delay_data.class3_individual[position] -= qty;
+    case 3:
+	delay_data[pool].class3->aggregate -= qty;
+	delay_data[pool].class3->network[position >> 8] -= qty;
+	delay_data[pool].class3->individual[position] -= qty;
 	return;
     }
+    fatalf("delayBytesWanted: Invalid class %d\n", class);
     assert(0);
 }
 
