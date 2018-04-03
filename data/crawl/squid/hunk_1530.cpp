 
 acl_httpstatus_data::acl_httpstatus_data(int x, int y) : status1(x), status2(y) { ; }
 
-void acl_httpstatus_data::toStr(char* buf, int len) const
+SBuf
+acl_httpstatus_data::toStr() const
 {
+    SBuf rv;
     if (status2 == INT_MAX)
-        snprintf(buf, len, "%d-", status1);
+        rv.Printf("%d-", status1);
     else if (status1 == status2)
-        snprintf(buf, len, "%d", status1);
+        rv.Printf("%d", status1);
     else
-        snprintf(buf, len, "%d-%d", status1, status2);
+        rv.Printf("%d-%d", status1, status2);
+    return rv;
 }
 
 int acl_httpstatus_data::compare(acl_httpstatus_data* const& a, acl_httpstatus_data* const& b)
