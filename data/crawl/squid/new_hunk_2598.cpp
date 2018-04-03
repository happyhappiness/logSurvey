    Config.onoff.relaxed_header_parser = 0;
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_BAD_REQUEST, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp(" / HTTP/1.0\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.m_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_end);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // binary code in method (strange but ...)
    input.append("GET\x0B / HTTP/1.1\n", 16);
    //printf("TEST: %d-%d/%d '%.*s'\n", output.req.start, output.req.end, input.contentSize(), 16, input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_OK, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET\x0B / HTTP/1.1\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(3, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET\x0B", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(5, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(5, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(7, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(14, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/1.1", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_min);
    input.reset();

    // CR in method
