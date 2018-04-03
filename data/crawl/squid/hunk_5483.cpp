 		DUMP_EXT_ACL_TYPE(PORT);
 		DUMP_EXT_ACL_TYPE(PATH);
 		DUMP_EXT_ACL_TYPE(METHOD);
+	    case _external_acl_format::EXT_ACL_USER_CERT:
+		storeAppendPrintf(sentry, " %%USER_CERT_%s", format->header);
+		break;
+	    case _external_acl_format::EXT_ACL_CA_CERT:
+		storeAppendPrintf(sentry, " %%USER_CERT_%s", format->header);
+		break;
+	    case _external_acl_format::EXT_ACL_UNKNOWN:
+	    case _external_acl_format::EXT_ACL_END:
+		fatal("unknown external_acl format error");
+		break;
 	    }
 	}
 	for (word = node->cmdline; word; word = word->next)
