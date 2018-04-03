             case _external_acl_format::EXT_ACL_##a: \
                 storeAppendPrintf(sentry, " %%%s", #a); \
                 break
+#define DUMP_EXT_ACL_TYPE_FMT(a, fmt, ...) \
+            case _external_acl_format::EXT_ACL_##a: \
+                storeAppendPrintf(sentry, fmt, ##__VA_ARGS__); \
+                break
 #if USE_AUTH
                 DUMP_EXT_ACL_TYPE(LOGIN);
 #endif
