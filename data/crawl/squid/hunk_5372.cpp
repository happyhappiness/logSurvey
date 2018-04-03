 aclParseWordList(void *curlist)
 {
     char *t = NULL;
+
     while ((t = strtokFile()))
-	wordlistAdd((wordlist **)curlist, t);
+        wordlistAdd((wordlist **)curlist, t);
 }
+
 #endif
 
 ACL *
 ACL::Factory (char const *type)
 {
     ACL *result = Prototype::Factory (type);
+
     if (result)
-	return result;
+        return result;
+
     squid_acl const acltype = aclStrToType(type);
+
     switch (acltype) {
-      case ACL_URL_PORT:
-      case ACL_MY_PORT:
-      case ACL_MAXCONN:
-      case ACL_PROTO:
-      case ACL_METHOD:
-      case ACL_SRC_ASN:
-      case ACL_DST_ASN:
+
+    case ACL_URL_PORT:
+
+    case ACL_MY_PORT:
+
+    case ACL_MAXCONN:
+
+    case ACL_PROTO:
+
+    case ACL_METHOD:
+
+    case ACL_SRC_ASN:
+
+    case ACL_DST_ASN:
 #if SQUID_SNMP
-      case ACL_SNMP_COMMUNITY:
+
+    case ACL_SNMP_COMMUNITY:
 #endif
 #if SRC_RTT_NOT_YET_FINISHED
-      case ACL_NETDB_SRC_RTT:
+
+    case ACL_NETDB_SRC_RTT:
 #endif
 #if USE_ARP_ACL
-      case ACL_SRC_ARP:
+
+    case ACL_SRC_ARP:
 #endif
-      case ACL_REP_MIME_TYPE:
-      case ACL_MAX_USER_IP:
-      case ACL_EXTERNAL:
-	result = new ACL(acltype);
-	break;
-      case ACL_DERIVED:
-      default:
-	fatal ("Unknown acl type in ACL::Factory");
+
+    case ACL_REP_MIME_TYPE:
+
+    case ACL_MAX_USER_IP:
+
+    case ACL_EXTERNAL:
+        result = new ACL(acltype);
+        break;
+
+    case ACL_DERIVED:
+
+    default:
+        fatal ("Unknown acl type in ACL::Factory");
     };
+
     assert (result);
+
     return result;
 }
 
 ACL::ACL (squid_acl const acltype) : type (acltype)
-{
-}
+{}
 
 ACL::ACL () : type(ACL_NONE)
-{
-}
+{}
 
 char const *
 ACL::typeString() const
