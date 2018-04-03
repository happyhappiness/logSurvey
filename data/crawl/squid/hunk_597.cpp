 {
     ACLFilledChecklist *checklist = Filled(ch);
     HttpRequest *request = checklist->request;
-    http_hdr_type headertype;
+    Http::HdrType headertype;
 
     if (NULL == request) {
         fatal ("requiresRequest SHOULD have been true for this ACL!!");
