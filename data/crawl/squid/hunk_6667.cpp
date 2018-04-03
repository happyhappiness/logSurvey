                 size2id_array[0]=realloc(size2id_array[0],size2id_alloc*sizeof(int));
                 size2id_array[1]=realloc(size2id_array[1],size2id_alloc*sizeof(int));
 	}
+	
 	size2id_array[0][size2id_len-1]=sz;
-	size2id_array[1][size2id_len-1]=0;
-	return size2id_len-1;
+	size2id_array[1][size2id_len-1]++;
+}
+
+void
+badformat()
+{
+    fprintf(stderr,"pummel.bad.format\n");
+    exit(1);
 }
 
+/* unused code, saved for parts */
+const char *
+make_nam(int id, int size)
+{
+    const char *buf = malloc(30); /* argh */
+    sprintf((char *)buf, "pl:%d/%d", id, size);
+    return buf;
+}