     AccessListTail = &A->next;
 }
 
+int aclMatchAcl(acl, c, pr, h, po, r)
+     struct _acl *acl;
+     in_addr c;
+     prototype_t pr;
+     char *h;
+     int po;
+     char *r;
+{
+    if (!acl)
+	return 0;
+    switch (acl->type) {
+    case ACL_SRC_IP:
+	return aclMatchIp(acl->data, c);
+	break;
+    case ACL_DST_DOMAIN:
+	return aclMatchWord(acl->data, h);
+	break;
+    case ACL_TIME:
+	debug(28, 0, "aclMatchAcl: ACL_TIME unimplemented\n");
+	return 0;
+	break;
+    case ACL_URL_REGEX:
+	return aclMatchRegex(acl->data, r);
+	break;
+    case ACL_URL_PORT:
+	return aclMatchInteger(acl->data, po);
+	break;
+    case ACL_USER:
+	debug(28, 0, "aclMatchAcl: ACL_USER unimplemented\n");
+	return 0;
+	break;
+    case ACL_PROTO:
+	return aclMatchInteger(acl->data, pr);
+	break;
+    case ACL_NONE:
+    default:
+	debug(28, 0, "aclMatchAcl: '%s' has bad type %d\n",
+	    acl->name, acl->type);
+	return 0;
+    }
+    fatal_dump("aclMatchAcl: This should never happen.");
+    return 0;
+}
+
+int aclMatchAclList(list, c, pr, h, po, r)
+     struct _acl_list *list;
+     in_addr c;
+     prototype_t pr;
+     char *h;
+     int po;
+     char *r;
+{
+    struct _acl *a = NULL;
+    while (list) {
+	if (aclMatchAcl(list->acl, c, pr, h, po, r) != list->op)
+		return 0;
+    }
+    return 1;
+}
+
+int aclCheck(cli_addr, proto, host, port, request)
+     in_addr cli_addr;
+     prototype_t proto;
+     char *host;
+     int port;
+     char *request;
+{
+    struct _acl_access *A = NULL;
+    int allow = 0;
 
-    if (regcomp(&comp, pattern, REG_EXTENDED) != REG_NOERROR) {
-	debug(22, 0, "ttlAddToList: Invalid regular expression: %s\n",
-	    pattern);
-	return;
+    for (A = AccessList; A; A = A->next) {
+	allow = A->allow;
+	if (aclMatchAclList(A->acl_list, cli_addr, proto, host, port, request))
+	    return allow;
     }
-    pct_age = pct_age < 0 ? 0 : pct_age > 100 ? 100 : pct_age;
-    age_max = age_max < 0 ? 0 : age_max;
+    return !allow;
+}