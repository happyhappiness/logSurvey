     fprintf(fp, "}\n\n");
 }
 
-static int defined(char *name)
+static int
+defined(char *name)
 {
-	int i=0;
-	if (!name)
-	    return 1;
-	for(i=0;strcmp(defines[i].name, name) != 0; i++) {
-	    assert(defines[i].name);
-	}
-	return defines[i].defined;
+    int i = 0;
+    if (!name)
+	return 1;
+    for (i = 0; strcmp(defines[i].name, name) != 0; i++) {
+	assert(defines[i].name);
+    }
+    return defines[i].defined;
 }
 
-static const char *available_if(char *name)
+static const char *
+available_if(char *name)
 {
-	int i=0;
-	assert(name);
-	for(i=0;strcmp(defines[i].name, name) != 0; i++) {
-	    assert(defines[i].name);
-	}
-	return defines[i].enable;
+    int i = 0;
+    assert(name);
+    for (i = 0; strcmp(defines[i].name, name) != 0; i++) {
+	assert(defines[i].name);
+    }
+    return defines[i].enable;
 }
 
 static void
