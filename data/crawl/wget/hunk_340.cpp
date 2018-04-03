       AC_CHECK_LIB(dl, shl_load)
     ])
 
-    AC_CHECK_LIB(z, compress)
-    AC_CHECK_LIB(crypto, EVP_MD_CTX_init)
-    AC_CHECK_LIB(ssl, ERR_func_error_string,,
-                AC_MSG_ERROR([openssl development libraries not found]))
-   AC_LIBOBJ([openssl])
+    case $host_os in
+      *mingw32* )
+        dnl prefer link to openssl dlls if possible. if not then fallback on static libs. if not then error
+        
+        AC_CHECK_LIB(eay32, EVP_MD_CTX_init)
+        if test x"$ac_cv_lib_eay32_EVP_MD_CTX_init" != xno
+        then
+          AC_CHECK_LIB(ssl32, SSL_connect,,
+                    AC_MSG_ERROR([openssl not found: shared lib eay32 found but ssl32 not found]))
+		  AC_MSG_NOTICE([Enabling support for SSL via OpenSSL (shared)])
+		else
+
+        case $host_os in
+            *mingw32* )
+                LIBS+=' -lgdi32'
+            ;;
+        esac
+
+		    dnl fallback and test static libs
+        AC_CHECK_LIB(crypto, EVP_MD_CTX_init,,,)
+		    if test x"$ac_cv_lib_crypto_EVP_MD_CTX_init" != xno
+		    then
+            AC_CHECK_LIB(ssl, SSL_connect,, AC_MSG_ERROR([openssl not found]))
+            AC_MSG_NOTICE([Enabling support for SSL via OpenSSL])
+        else
+		        AC_MSG_ERROR([openssl not found: shared (eay32/ssl32) or static (crypto/ssl) libs needed])
+		    fi
+    fi
+		
+        dnl add zdll lib as dep for above tests?
+      ;;
+      *)
+
+        AC_CHECK_LIB(crypto, EVP_MD_CTX_init)
+        AC_CHECK_LIB(ssl, ERR_func_error_string,,
+                  AC_MSG_ERROR([openssl development libraries not found]))
+        AC_MSG_NOTICE([Enabling support for SSL via OpenSSL (static)])
+      ;;
+    esac
+    AC_LIBOBJ([openssl])
 ], [
   # --with-ssl is not gnutls: check if it's no
   AS_IF([test x"$with_ssl" != xno], [
