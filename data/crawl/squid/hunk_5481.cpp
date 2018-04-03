     case ACL_EXTERNAL:
 	aclParseExternal(&A->data);
 	break;
+#if USE_SSL
+    case ACL_USER_CERT:
+    case ACL_CA_CERT:
+	aclParseCertList(&A->data);
+	break;
+#endif
     case ACL_NONE:
     case ACL_ENUM_MAX:
 	fatal("Bad ACL type");
