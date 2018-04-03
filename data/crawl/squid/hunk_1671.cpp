     CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
     input.reset();
 }
+
+void
+testHttpParser::testDripFeed()
+{
+    // Simulate a client drip-feeding Squid a few bytes at a time.
+    // extend the size of the buffer from 0 bytes to full request length
+    // calling the parser repeatedly as visible data grows.
+
+    MemBuf mb;
+    mb.init(1024, 1024);
+    mb.append("            ", 12);
+    int garbageEnd = mb.contentSize();
+    mb.append("GET http://example.com/ HTTP/1.1\r\n", 34);
+    int reqLineEnd = mb.contentSize();
+    mb.append("\n", 1);
+
+    HttpParser hp(mb.content(), 0);
+
+    // only relaxed parser accepts the garbage whitespace
+    Config.onoff.relaxed_header_parser = 1;
+
+    for (; hp.bufsiz < mb.contentSize(); ++hp.bufsiz) {
+        int parseResult = hp.parseRequestFirstLine();
+
+#if WHEN_TEST_DEBUG_IS_NEEDED
+        printf("%d/%d :: %d, %d, %d '%c'\n", hp.bufsiz, mb.contentSize(),
+               garbageEnd, reqLineEnd, parseResult,
+               mb.content()[hp.bufsiz]);
+#endif
+
+	// before end of garbage found its a moving offset.
+	if (hp.bufsiz < garbageEnd) {
+            CPPUNIT_ASSERT_EQUAL(hp.bufsiz, (int)hp.parseOffset_);
+            continue;
+        }
+
+	// before request line found, parse announces incomplete
+        if (hp.bufsiz < reqLineEnd) {
+            CPPUNIT_ASSERT_EQUAL(garbageEnd, (int)hp.parseOffset_);
+            CPPUNIT_ASSERT_EQUAL(0, parseResult);
+            continue;
+        }
+
+        // once request line is found (AND the following \n) current parser announces success
+        CPPUNIT_ASSERT_EQUAL(reqLineEnd, (int)hp.parseOffset_);
+        CPPUNIT_ASSERT_EQUAL(1, parseResult);
+    }
+}
