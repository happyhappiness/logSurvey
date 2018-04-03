     *list = NULL;
 }
 
-static void
-aclDestroyIntRange(intrange * list)
-{
-    intrange *w = NULL;
-    intrange *n = NULL;
-
-    for (w = list; w; w = n) {
-        n = w->next;
-        safe_free(w);
-    }
-}
-
-wordlist *
-aclDumpRegexList(relist * data)
-{
-    wordlist *W = NULL;
-
-    while (data != NULL) {
-        wordlistAdd(&W, data->pattern);
-        data = data->next;
-    }
-
-    return W;
-}
-
-static wordlist *
-aclDumpIntlistList(intlist * data)
-{
-    wordlist *W = NULL;
-    char buf[32];
-
-    while (data != NULL) {
-        snprintf(buf, sizeof(buf), "%d", data->i);
-        wordlistAdd(&W, buf);
-        data = data->next;
-    }
-
-    return W;
-}
-
-static wordlist *
-aclDumpIntRangeList(intrange * data)
-{
-    wordlist *W = NULL;
-    char buf[32];
-
-    while (data != NULL) {
-        if (data->i == data->j)
-            snprintf(buf, sizeof(buf), "%d", data->i);
-        else
-            snprintf(buf, sizeof(buf), "%d-%d", data->i, data->j);
-
-        wordlistAdd(&W, buf);
-
-        data = data->next;
-    }
-
-    return W;
-}
-
-static wordlist *
-aclDumpProtoList(intlist * data)
-{
-    wordlist *W = NULL;
-
-    while (data != NULL) {
-        wordlistAdd(&W, ProtocolStr[data->i]);
-        data = data->next;
-    }
-
-    return W;
-}
-
-static wordlist *
-aclDumpMethodList(intlist * data)
-{
-    wordlist *W = NULL;
-
-    while (data != NULL) {
-        wordlistAdd(&W, RequestMethodStr[data->i]);
-        data = data->next;
-    }
-
-    return W;
-}
-
 wordlist *
 ACL::dumpGeneric () const
 {
-    debug(28, 3) ("ACL::dumpGeneric: %s type %d\n", name, aclType());
+    debug(28, 3) ("ACL::dumpGeneric: %s type %s\n", name, typeString());
     return dump();
 }
 
-wordlist *
-ACL::dump() const
-{
-    switch (aclType()) {
-#if SQUID_SNMP
-
-    case ACL_SNMP_COMMUNITY:
-        return wordlistDup((wordlist *)data);
-#endif
-
-    case ACL_DERIVED:
-        fatal ("unused");
-
-    case ACL_REP_MIME_TYPE:
-        return aclDumpRegexList((relist *)data);
-
-    case ACL_SRC_ASN:
-
-    case ACL_MAXCONN:
-
-    case ACL_DST_ASN:
-        return aclDumpIntlistList((intlist *)data);
-
-    case ACL_MAX_USER_IP:
-        return aclDumpUserMaxIP(data);
-
-    case ACL_URL_PORT:
-
-    case ACL_MY_PORT:
-        return aclDumpIntRangeList((intrange *)data);
-
-    case ACL_PROTO:
-        return aclDumpProtoList((intlist *)data);
-
-    case ACL_METHOD:
-        return aclDumpMethodList((intlist *)data);
-#if USE_ARP_ACL
-
-    case ACL_SRC_ARP:
-        return aclDumpArpList(data);
-#endif
-
-    case ACL_EXTERNAL:
-        return aclDumpExternal(data);
-
-    case ACL_NONE:
-
-    case ACL_ENUM_MAX:
-        break;
-    }
-
-    debug(28, 1) ("ACL::dumpGeneric: no case for ACL type %d\n", aclType());
-    return NULL;
-}
-
 /*
  * This function traverses all ACL elements referenced
  * by an access list (presumably 'http_access').   If 
  * it finds a PURGE method ACL, then it returns TRUE,
  * otherwise FALSE.
  */
+/* XXX: refactor this more sensibly. perhaps have the parser detect it ? */
 int
 aclPurgeMethodInUse(acl_access * a)
 {
     return a->containsPURGE();
 }
 
+#include "ACLStrategised.h"
 bool
 acl_access::containsPURGE() const
 {
