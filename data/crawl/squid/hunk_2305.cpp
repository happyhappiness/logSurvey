     input.reset();
 
     // RFC 2616 : future version full-request
+    input.append("GET / HTTP/1.2\r\n", 16);
+    //printf("TEST: '%s'\n",input.content());
+    output.reset(input.content(), input.contentSize());
+    CPPUNIT_ASSERT_EQUAL(1, HttpParserParseReqLine(&output));
+    CPPUNIT_ASSERT_EQUAL(HTTP_OK, output.request_parse_status);
+    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
+    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
+    CPPUNIT_ASSERT(memcmp("GET / HTTP/1.2\r\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
+    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
+    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
+    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
+    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
+    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
+    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
+    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
+    CPPUNIT_ASSERT_EQUAL(13, output.req.v_end);
+    CPPUNIT_ASSERT(memcmp("HTTP/1.2", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
+    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
+    CPPUNIT_ASSERT_EQUAL(2, output.req.v_min);
+    input.reset();
+
+    // RFC 2616 : future version full-request
+    // XXX: IETF HTTPbis WG has made this two-digits format invalid.
     input.append("GET / HTTP/10.12\r\n", 18);
     //printf("TEST: '%s'\n",input.content());
     output.reset(input.content(), input.contentSize());
