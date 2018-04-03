 		die("failed to apply delta");
 	free(delta);
 	write_object(nr, type, result, result_size);
+	free(result);
 }
 
 static void added_object(unsigned nr, enum object_type type,
