 {
     if (top->left)
 	splay_walk(top->left, walkee, state);
+    walkee(top->data, state);
     if (top->right)
 	splay_walk(top->right, walkee, state);
-    walkee(top->data, state);
 }
 
+#ifdef DEBUG
+void
+splay_dump_entry(void *data, int depth)
+{
+    printf("%*s%s\n", depth, "", (char *) data);
+}
 
-
-#ifdef DRIVER
+static void
+splay_do_dump(splayNode * top, void printfunc(void *data, int depth), int depth)
+{
+    if (!top)
+	return;
+    splay_do_dump(top->left, printfunc, depth + 1);
+    printfunc(top->data, depth);
+    splay_do_dump(top->right, printfunc, depth + 1);
+}
 
 void
-splay_print(splayNode * top, void (*printfunc) ())
+splay_dump(splayNode * top, void printfunc(void *data, int depth))
 {
-    if (top == NULL)
-	return;
-    splay_print(top->left, printfunc);
-    printfunc(top->data);
-    splay_print(top->right, printfunc);
+    splay_do_dump(top, printfunc, 0);
 }
 
+
+#endif
+
+#ifdef DRIVER
+
 typedef struct {
     int i;
 } intnode;
