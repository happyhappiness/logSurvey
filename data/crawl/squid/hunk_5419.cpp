 }
 
 wordlist *
-aclDumpGeneric(const acl * a)
-{
-    debug(28, 3) ("aclDumpGeneric: %s type %d\n", a->name, a->type);
-    switch (a->type) {
-    case ACL_SRC_IP:
-    case ACL_DST_IP:
-    case ACL_MY_IP:
-	return aclDumpIpList(a->data);
+ACL::dumpGeneric () const
+{
+    debug(28, 3) ("ACL::dumpGeneric: %s type %d\n", name, aclType());
+    return dump();
+}
+
+wordlist *
+ACL::dump() const
+{
+    switch (aclType()) {
     case ACL_SRC_DOMAIN:
     case ACL_DST_DOMAIN:
-	return aclDumpDomainList(a->data);
+	return aclDumpDomainList(data);
 #if SQUID_SNMP
     case ACL_SNMP_COMMUNITY:
-	return wordlistDup((wordlist *)a->data);
+	return wordlistDup((wordlist *)data);
 #endif
 #if USE_IDENT
-    case ACL_IDENT:
-	return aclDumpUserList((acl_user_data *)a->data);
     case ACL_IDENT_REGEX:
-	return aclDumpRegexList((relist *)a->data);
+	return aclDumpRegexList((relist *)data);
+#endif
+#if USE_IDENT
+    case ACL_IDENT:
 #endif
+    case ACL_DERIVED:
     case ACL_PROXY_AUTH:
-	return aclDumpUserList((acl_user_data *)a->data);
+	fatal ("unused");
     case ACL_TIME:
-	return aclDumpTimeSpecList((acl_time_data *)a->data);
+	return aclDumpTimeSpecList((acl_time_data *)data);
     case ACL_PROXY_AUTH_REGEX:
     case ACL_URL_REGEX:
     case ACL_URLPATH_REGEX:
