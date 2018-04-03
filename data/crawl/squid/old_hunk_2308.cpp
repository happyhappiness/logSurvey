    CPPUNIT_ASSERT_EQUAL(1, output.req.v_min);
    input.reset();

    // This stage of the parser does not yet accept non-HTTP protocol names.
    // violations mode treats them as HTTP/0.9 requests!
    input.append("GET / FOO/1.0\n", 14);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
#if USE_HTTP_VIOLATIONS
    CPPUNIT_ASSERT_EQUAL(1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_OK, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(12, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/ FOO/1.0", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(9, output.req.v_min);
#else
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
#endif
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / FOO/1.0\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(12, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("FOO/1.0", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    input.reset();

    // RELAXED space padded method (in strict mode SP is reserved so invalid as a method byte)
