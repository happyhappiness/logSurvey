  */
 bool
 
-acl_ip_data::DecodeAddress(const char *asc, struct in_addr *addr, struct in_addr *mask)
+acl_ip_data::DecodeMask(const char *asc, struct in_addr *mask)
 {
-    u_int32_t a;
-    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
+    char junk;
+    int a1 = 0;
 
-    switch (sscanf(asc, "%d.%d.%d.%d", &a1, &a2, &a3, &a4))
+    if (!asc || !*asc)
     {
-
-    case 4:			/* a dotted quad */
-
-        if (!safe_inet_addr(asc, addr)) {
-            debug(28, 0) ("DecodeAddress: unsafe IP address: '%s'\n", asc);
-            fatal("DecodeAddress: unsafe IP address");
-        }
-
-        break;
-
-    case 1:			/* a significant bits value for a mask */
-
-        if (a1 >= 0 && a1 < 33) {
-            addr->s_addr = a1 ? htonl(0xfffffffful << (32 - a1)) : 0;
-            break;
-        }
-
-    default:
-        debug(28, 0) ("DecodeAddress: Invalid IP address '%s'\n", asc);
-        return 0;		/* This is not valid address */
+        mask->s_addr = htonl(0xFFFFFFFFul);
+        return 1;
     }
 
-    if (mask != NULL)
-    {		/* mask == NULL if called to decode a netmask */
+    if (sscanf(asc, "%d%c", &a1, &junk) == 1 && a1 >= 0 && a1 < 33)
+    {		/* a significant bits value for a mask */
+        mask->s_addr = a1 ? htonl(0xfffffffful << (32 - a1)) : 0;
+        return 1;
+    }
 
-        /* Guess netmask */
-        a = (u_int32_t) ntohl(addr->s_addr);
+    /* dotted notation */
+    if (safe_inet_addr(asc, mask))
+        return 1;
 
-        if (!(a & 0xFFFFFFFFul))
-            mask->s_addr = htonl(0x00000000ul);
-        else if (!(a & 0x00FFFFFF))
-            mask->s_addr = htonl(0xFF000000ul);
-        else if (!(a & 0x0000FFFF))
-            mask->s_addr = htonl(0xFFFF0000ul);
-        else if (!(a & 0x000000FF))
-            mask->s_addr = htonl(0xFFFFFF00ul);
-        else
-            mask->s_addr = htonl(0xFFFFFFFFul);
-    }
+    debug(28, 0) ("DecodeAddress: Invalid IP address: '%s'\n", asc);
 
-    return 1;
+    return 0;
 }
 
 #define SCAN_ACL1       "%[0123456789.]-%[0123456789.]/%[0123456789.]"
 #define SCAN_ACL2       "%[0123456789.]-%[0123456789.]%c"
 #define SCAN_ACL3       "%[0123456789.]/%[0123456789.]"
-#define SCAN_ACL4       "%[0123456789.]%c"
 
 acl_ip_data *
 acl_ip_data::FactoryParse(const char *t)
