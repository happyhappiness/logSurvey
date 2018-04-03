     CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_len,
                           ((struct sockaddr_in6*)ipval->ai_addr)->sin6_len );
     CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_in6*)ipval->ai_addr)->sin6_len, ipval->ai_addrlen );
+#endif
+#if HAVE_SIN_LEN_IN_SAI
+    CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in*)expect->ai_addr)->sin_len,
+                          ((struct sockaddr_in*)ipval->ai_addr)->sin_len );
+    CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_in*)ipval->ai_addr)->sin_len, ipval->ai_addrlen );
 #endif
     CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_family,
                           ((struct sockaddr_in6*)ipval->ai_addr)->sin6_family );
     CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_in6*)expect->ai_addr)->sin6_port,
                           ((struct sockaddr_in6*)ipval->ai_addr)->sin6_port );
 #else
 #if HAVE_SS_LEN_IN_SS
-    printf("\nSYS SS_LEN=%d\nSQD SS_LEN=%d\n",((struct sockaddr_storage*)expect->ai_addr)->ss_len,
-           ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
     CPPUNIT_ASSERT_EQUAL( ((struct sockaddr_storage*)expect->ai_addr)->ss_len,
                           ((struct sockaddr_storage*)ipval->ai_addr)->ss_len );
     CPPUNIT_ASSERT_EQUAL( (socklen_t)((struct sockaddr_storage*)ipval->ai_addr)->ss_len, ipval->ai_addrlen );