     case ACL_DST_DOM_REGEX:
     case ACL_REQ_MIME_TYPE:
     case ACL_REP_MIME_TYPE:
-	aclParseRegexList(&A->data);
+	aclParseRegexList(&data);
 	break;
     case ACL_SRC_ASN:
     case ACL_MAXCONN:
     case ACL_DST_ASN:
-	aclParseIntlist(&A->data);
+	aclParseIntlist(&data);
 	break;
     case ACL_MAX_USER_IP:
-	aclParseUserMaxIP(&A->data);
+	aclParseUserMaxIP(&data);
 	break;
 #if SRC_RTT_NOT_YET_FINISHED
     case ACL_NETDB_SRC_RTT:
-	aclParseIntlist(&A->data);
+	aclParseIntlist(&data);
 	break;
 #endif
     case ACL_URL_PORT:
     case ACL_MY_PORT:
-	aclParseIntRange(&A->data);
+	aclParseIntRange(&data);
 	break;
 #if USE_IDENT
-    case ACL_IDENT:
-	aclParseUserList(&A->data);
-	break;
     case ACL_IDENT_REGEX:
-	aclParseRegexList(&A->data);
+	aclParseRegexList(&data);
 	break;
 #endif
     case ACL_PROTO:
-	aclParseProtoList(&A->data);
+	aclParseProtoList(&data);
 	break;
     case ACL_METHOD:
-	aclParseMethodList(&A->data);
+	aclParseMethodList(&data);
 	break;
+#if USE_IDENT
+    case ACL_IDENT: 
+#endif
+    case ACL_DERIVED:
     case ACL_PROXY_AUTH:
-	if (authenticateSchemeCount() == 0) {
-	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
-because no authentication schemes were compiled.\n", A->cfgline);
-	} else if (authenticateActiveSchemeCount() == 0) {
-	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
-because no authentication schemes are fully configured.\n", A->cfgline);
-	} else {
-	    aclParseUserList(&A->data);
-	}
+	fatal ("unused");
 	break;
     case ACL_PROXY_AUTH_REGEX:
 	if (authenticateSchemeCount() == 0) {
 	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
-because no authentication schemes were compiled.\n", A->cfgline);
+because no authentication schemes were compiled.\n", cfgline);
 	} else if (authenticateActiveSchemeCount() == 0) {
 	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
-because no authentication schemes are fully configured.\n", A->cfgline);
+because no authentication schemes are fully configured.\n", cfgline);
 	} else {
-	    aclParseRegexList(&A->data);
+	    aclParseRegexList(&data);
 	}
 	break;
 #if SQUID_SNMP
     case ACL_SNMP_COMMUNITY:
-	aclParseWordList(&A->data);
+	aclParseWordList(&data);
 	break;
 #endif
 #if USE_ARP_ACL
     case ACL_SRC_ARP:
-	aclParseArpList(&A->data);
+	aclParseArpList(&data);
 	break;
 #endif
     case ACL_EXTERNAL:
-	aclParseExternal(&A->data);
+	aclParseExternal(&data);
 	break;
 #if USE_SSL
     case ACL_USER_CERT:
     case ACL_CA_CERT:
-	aclParseCertList(&A->data);
+	aclParseCertList(&data);
 	break;
 #endif
     case ACL_NONE:
     case ACL_ENUM_MAX:
 	fatal("Bad ACL type");
 	break;
     }
-    /*
-     * Clear AclMatchedName from our temporary hack
-     */
-    AclMatchedName = NULL;	/* ugly */
-    if (!new_acl)
-	return;
-    if (A->data == NULL) {
-	debug(28, 0) ("aclParseAclLine: IGNORING invalid ACL: %s\n",
-	    A->cfgline);
-	memFree(A, MEM_ACL);
-	return;
-    }
-    /* append */
-    while (*head)
-	head = &(*head)->next;
-    *head = A;
 }
 
 /* does name lookup, returns page_id */
