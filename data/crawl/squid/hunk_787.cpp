         }
     }
 
-    contextMethod = Ssl::contextMethod(version);
-    if (!contextMethod)
-        fatalf("Unable to compute context method to use");
+    // backward compatibility hack for sslversion= configuration
+    if (version > 2) {
+        const char *add = NULL;
+        switch (version) {
+        case 3:
+            add = "NO_TLSv1,NO_TLSv1_1,NO_TLSv1_2";
+            break;
+        case 4:
+            add = "NO_SSLv3,NO_TLSv1_1,NO_TLSv1_2";
+            break;
+        case 5:
+            add = "NO_SSLv3,NO_TLSv1,NO_TLSv1_2";
+            break;
+        case 6:
+            add = "NO_SSLv3,NO_TLSv1,NO_TLSv1_1";
+            break;
+        default: // nothing
+            break;
+        }
+        if (add) {
+            SBuf tmpOpts;
+            if (options) {
+                tmpOpts.append(options, strlen(options));
+                tmpOpts.append(",",1);
+            }
+            tmpOpts.append(add, strlen(add));
+            xfree(options);
+            options = xstrdup(tmpOpts.c_str());
+        }
+        version = 0; // prevent options being repeatedly appended
+    }
+
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+    contextMethod = TLS_server_method();
+#else
+    contextMethod = SSLv23_server_method();
+#endif
 
     if (dhfile)
         dhParams.reset(Ssl::readDHParams(dhfile));
