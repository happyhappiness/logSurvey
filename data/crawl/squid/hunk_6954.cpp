 
 #ifdef TEST
 main(argc, argv)
-    int argc;
-    char *argv[];
+     int argc;
+     char *argv[];
 {
     FILE *fp;
     struct node *nodes;
     struct tree *tp;
 
     fp = fopen("mib.txt", "r");
-    if (fp == NULL){
+    if (fp == NULL) {
 	fprintf(stderr, "open failed\n");
 	return 1;
     }
