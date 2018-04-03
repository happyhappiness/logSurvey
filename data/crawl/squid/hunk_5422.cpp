     return 0;
 }
 
-SQUIDCEXTERN void aclChecklistFree(ACLChecklist *)
+void
+ACLChecklist::operator delete (void *address)
 {
-    fatal ("dummy function\n");
+    safe_free( address);
 }
 
+ACLChecklist::~ACLChecklist(){}
+
 SQUIDCEXTERN void fatal (char const *msg)
 {
     printf ("%s\n",msg);