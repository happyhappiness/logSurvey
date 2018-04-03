     AnyP::ProtocolVersion version;
 };
 
+// define SQUID_DEBUG_TESTS to see exactly which test sub-cases fail and where
+#ifdef SQUID_DEBUG_TESTS
+// not optimized for runtime use
+static void
+Replace(SBuf &where, const SBuf &what, const SBuf &with)
+{
+    // prevent infinite loops
+    if (!what.length() || with.find(what) != SBuf::npos)
+        return;
+
+    SBuf::size_type pos = 0;
+    while ((pos = where.find(what, pos)) != SBuf::npos) {
+        SBuf buf = where.substr(0, pos);
+        buf.append(with);
+        buf.append(where.substr(pos+what.length()));
+        where = buf;
+        pos += with.length();
+    }
+}
+
+static SBuf Pretty(SBuf raw)
+{
+    Replace(raw, SBuf("\r"), SBuf("\\r"));
+    Replace(raw, SBuf("\n"), SBuf("\\n"));
+    return raw;
+}
+#endif
+
 static void
 testResults(int line, const SBuf &input, Http1::RequestParser &output, struct resultSet &expect)
 {
-#if WHEN_TEST_DEBUG_IS_NEEDED
-    printf("TEST @%d, in=%u: " SQUIDSBUFPH "\n", line, input.length(), SQUIDSBUFPRINT(input));
+#ifdef SQUID_DEBUG_TESTS
+    std::cerr << "TEST @" << line << ", in=" << Pretty(input) << "\n";
+#endif
+
+    const bool parsed = output.parse(input);
+
+#ifdef SQUID_DEBUG_TESTS
+    if (expect.parsed != parsed)
+        std::cerr << "\tparse-FAILED: " << expect.parsed << "!=" << parsed << "\n";
+    else if (parsed && expect.method != output.method_)
+        std::cerr << "\tmethod-FAILED: " << expect.method << "!=" << output.method_ << "\n";
+    if (expect.status != output.parseStatusCode)
+        std::cerr << "\tscode-FAILED: " << expect.status << "!=" << output.parseStatusCode << "\n";
+    if (expect.suffixSz != output.buf_.length())
+        std::cerr << "\tsuffixSz-FAILED: " << expect.suffixSz << "!=" << output.buf_.length() << "\n";
 #endif
 
     // runs the parse
-    CPPUNIT_ASSERT_EQUAL(expect.parsed, output.parse(input));
+    CPPUNIT_ASSERT_EQUAL(expect.parsed, parsed);
+
+    // if parsing was successful, check easily visible field outputs
+    if (parsed) {
+        CPPUNIT_ASSERT_EQUAL(expect.method, output.method_);
+        if (expect.uri != NULL)
+            CPPUNIT_ASSERT_EQUAL(0, output.uri_.cmp(expect.uri));
+        CPPUNIT_ASSERT_EQUAL(expect.version, output.msgProtocol_);
+    }
 
-    // check easily visible field outputs
-    CPPUNIT_ASSERT_EQUAL(expect.method, output.method_);
-    if (expect.uri != NULL)
-        CPPUNIT_ASSERT_EQUAL(0, output.uri_.cmp(expect.uri));
-    CPPUNIT_ASSERT_EQUAL(expect.version, output.msgProtocol_);
     CPPUNIT_ASSERT_EQUAL(expect.status, output.parseStatusCode);
 
     // check more obscure states
