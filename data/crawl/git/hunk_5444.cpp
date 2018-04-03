 	return ret;
 }
 
+void *xmallocz(size_t size)
+{
+	void *ret;
+	if (size + 1 < size)
+		die("Data too large to fit into virtual memory space.");
+	ret = xmalloc(size + 1);
+	((char*)ret)[size] = 0;
+	return ret;
+}
+
 /*
  * xmemdupz() allocates (len + 1) bytes of memory, duplicates "len" bytes of
  * "data" to the allocated memory, zero terminates the allocated memory,
