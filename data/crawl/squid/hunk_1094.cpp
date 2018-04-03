         String vh=virgin.header->header.getByName("Proxy-Authorization");
         buf.Printf("Proxy-Authorization: " SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(vh));
     } else if (request->extacl_user.size() > 0 && request->extacl_passwd.size() > 0) {
-        char loginbuf[256];
-        snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
-                 SQUIDSTRINGPRINT(request->extacl_user),
-                 SQUIDSTRINGPRINT(request->extacl_passwd));
-        buf.Printf("Proxy-Authorization: Basic %s\r\n", old_base64_encode(loginbuf));
+        struct base64_encode_ctx ctx;
+        base64_encode_init(&ctx);
+        uint8_t base64buf[base64_encode_len(MAX_LOGIN_SZ)];
+        size_t resultLen = base64_encode_update(&ctx, base64buf, request->extacl_user.size(), reinterpret_cast<const uint8_t*>(request->extacl_user.rawBuf()));
+        resultLen += base64_encode_update(&ctx, base64buf+resultLen, 1, reinterpret_cast<const uint8_t*>(":"));
+        resultLen += base64_encode_update(&ctx, base64buf+resultLen, request->extacl_passwd.size(), reinterpret_cast<const uint8_t*>(request->extacl_passwd.rawBuf()));
+        resultLen += base64_encode_final(&ctx, base64buf+resultLen);
+        buf.Printf("Proxy-Authorization: Basic %.*s\r\n", resultLen, base64buf);
     }
 
     // share the cross-transactional database records if needed
