 }
 #endif
 
+ACL *
+ACL::Factory (char const *type)
+{
+    ACL *result = Prototype::Factory (type);
+    if (result)
+	return result;
+    squid_acl const acltype = aclStrToType(type);
+    switch (acltype) {
+#if USE_IDENT
+      case ACL_IDENT:
+        result = new ACLIdent;
+	break;
+#endif
+      case ACL_PROXY_AUTH:
+        result = new ACLProxyAuth;
+	break;
+      case ACL_DST_DOMAIN:
+      case ACL_SRC_DOMAIN:
+      case ACL_DST_DOM_REGEX:
+      case ACL_SRC_DOM_REGEX:
+      case ACL_TIME:
+      case ACL_URLPATH_REGEX:
+      case ACL_URL_REGEX:
+      case ACL_URL_PORT:
+      case ACL_MY_PORT:
+      case ACL_MAXCONN:
+#if USE_IDENT
+      case ACL_IDENT_REGEX:
+#endif
+      case ACL_PROTO:
+      case ACL_METHOD:
+      case ACL_BROWSER:
+      case ACL_REFERER_REGEX:
+      case ACL_PROXY_AUTH_REGEX:
+      case ACL_SRC_ASN:
+      case ACL_DST_ASN:
+#if SQUID_SNMP
+      case ACL_SNMP_COMMUNITY:
+#endif
+#if SRC_RTT_NOT_YET_FINISHED
+      case ACL_NETDB_SRC_RTT:
+#endif
+#if USE_ARP_ACL
+      case ACL_SRC_ARP:
+#endif
+      case ACL_REQ_MIME_TYPE:
+      case ACL_REP_MIME_TYPE:
+      case ACL_MAX_USER_IP:
+      case ACL_EXTERNAL:
+#if USE_SSL
+      case ACL_USER_CERT:
+      case ACL_CA_CERT:
+#endif
+	result = new ACL(acltype);
+	break;
+      case ACL_DERIVED:
+      default:
+	fatal ("Unknown acl type in ACL::Factory");
+    };
+    assert (result);
+    return result;
+}
+
+ACL::ACL (squid_acl const acltype) : type (acltype)
+{
+}
+
+ACL::ACL () : type(ACL_NONE)
+{
+}
+
+char const *
+ACL::typeString() const
+{
+    return aclTypeToStr(aclType());
+}
+
 void
-aclParseAclLine(acl ** head)
+ACL::ParseAclLine(acl ** head)
 {
     /* we're already using strtok() to grok the line */
     char *t = NULL;
