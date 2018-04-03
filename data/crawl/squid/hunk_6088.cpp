 }
 
 void
-printint(void *a)
+printint(void *a, void *state)
 {
     intnode *A = a;
-    printf("%d\n", A->i);
+    printf("%d\n", "", A->i);
 }
 
 main(int argc, char *argv[])
