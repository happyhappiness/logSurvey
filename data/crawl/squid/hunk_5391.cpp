 #endif
     case ACL_DERIVED:
 	fatal ("unused");
-    case ACL_TIME:
-	return aclDumpTimeSpecList((acl_time_data *)data);
-    case ACL_URL_REGEX:
-    case ACL_URLPATH_REGEX:
-    case ACL_BROWSER:
-    case ACL_REFERER_REGEX:
-    case ACL_REQ_MIME_TYPE:
     case ACL_REP_MIME_TYPE:
 	return aclDumpRegexList((relist *)data);
     case ACL_SRC_ASN:
