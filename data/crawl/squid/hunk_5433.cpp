     return NULL;
 }
 
-SQUIDCEXTERN int aclCheckFast(const acl_access *A, ACLChecklist *)
+int aclCheckFast(const acl_access *A, ACLChecklist *)
 {
     fatal ("dummy function\n");
     return 0;
