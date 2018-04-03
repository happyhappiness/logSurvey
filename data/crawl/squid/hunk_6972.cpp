 
     for (i = 0; i < TEST_SIZE; ++i) {
 	file_map_bit_set(i);
-	if (!file_map_bit_test(i))
-	    fatal_dump(NULL);
+	assert(file_map_bit_test(i));
 	file_map_bit_reset(i);
     }
 }
