 
 static void
 dump_size_t(size_t var)
+{
+    printf("%d", (int) var);
+}
+
+static void
+dump_b_size_t(size_t var)
 {
     printf("%d bytes", (int) var);
 }
