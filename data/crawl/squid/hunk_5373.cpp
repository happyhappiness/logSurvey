 
 void
 ACL::parse()
-{    
+{
     switch (aclType()) {
+
     case ACL_REP_MIME_TYPE:
-	aclParseRegexList(&data);
-	break;
+        aclParseRegexList(&data);
+        break;
+
     case ACL_SRC_ASN:
+
     case ACL_MAXCONN:
+
     case ACL_DST_ASN:
-	aclParseIntlist(&data);
-	break;
+        aclParseIntlist(&data);
+        break;
+
     case ACL_MAX_USER_IP:
-	aclParseUserMaxIP(&data);
-	break;
+        aclParseUserMaxIP(&data);
+        break;
 #if SRC_RTT_NOT_YET_FINISHED
+
     case ACL_NETDB_SRC_RTT:
-	aclParseIntlist(&data);
-	break;
+        aclParseIntlist(&data);
+        break;
 #endif
+
     case ACL_URL_PORT:
+
     case ACL_MY_PORT:
-	aclParseIntRange(&data);
-	break;
+        aclParseIntRange(&data);
+        break;
+
     case ACL_PROTO:
-	aclParseProtoList(&data);
-	break;
+        aclParseProtoList(&data);
+        break;
+
     case ACL_METHOD:
-	aclParseMethodList(&data);
-	break;
+        aclParseMethodList(&data);
+        break;
+
     case ACL_DERIVED:
-	fatal ("overriden");
-	break;
+        fatal ("overriden");
+        break;
 #if SQUID_SNMP
+
     case ACL_SNMP_COMMUNITY:
-	aclParseWordList(&data);
-	break;
+        aclParseWordList(&data);
+        break;
 #endif
 #if USE_ARP_ACL
+
     case ACL_SRC_ARP:
-	aclParseArpList(&data);
-	break;
+        aclParseArpList(&data);
+        break;
 #endif
+
     case ACL_EXTERNAL:
-	aclParseExternal(&data);
-	break;
+        aclParseExternal(&data);
+        break;
+
     case ACL_NONE:
+
     case ACL_ENUM_MAX:
-	fatal("Bad ACL type");
-	break;
+        fatal("Bad ACL type");
+        break;
     }
 }
 
