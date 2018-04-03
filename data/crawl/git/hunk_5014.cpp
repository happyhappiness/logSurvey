 			uint32_t mark)
 {
 	/* Mode must be 100644, 100755, 120000, or 160000. */
-	printf("M %06o :%d ", mode, mark);
+	printf("M %06"PRIo32" :%"PRIu32" ", mode, mark);
 	pool_print_seq(depth, path, '/', stdout);
 	putchar('\n');
 }
