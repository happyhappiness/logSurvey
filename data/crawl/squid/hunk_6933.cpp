 
 #ifdef TEST
 print_subtree(tree, count)
-    struct tree *tree;
-    int count;
+     struct tree *tree;
+     int count;
 {
     struct tree *tp;
     int i;
 
-    for(i = 0; i < count; i++)
+    for (i = 0; i < count; i++)
 	printf("  ");
     printf("Children of %s:\n", tree->label);
     count++;
-    for(tp = tree->child_list; tp; tp = tp->next_peer){
-	for(i = 0; i < count; i++)
+    for (tp = tree->child_list; tp; tp = tp->next_peer) {
+	for (i = 0; i < count; i++)
 	    printf("  ");
 	printf("%s\n", tp->label);
     }
-    for(tp = tree->child_list; tp; tp = tp->next_peer){
+    for (tp = tree->child_list; tp; tp = tp->next_peer) {
 	print_subtree(tp, count);
     }
 }
