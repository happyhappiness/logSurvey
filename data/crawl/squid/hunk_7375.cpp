     debug(19, 6, "memCopy: offset %d: size %d\n", offset, size);
 
     if (p == NULL)
-	fatal_dump("memCopy: NULL mem_node");
+	return -1;
+    /*      fatal_dump("memCopy: NULL mem_node"); *//* Can happen on async */
 
     if (size <= 0)
 	return size;
