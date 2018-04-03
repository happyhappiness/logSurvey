    Config.onoff.relaxed_header_parser = 0;
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_BAD_REQUEST, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req_start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req_end);
    CPPUNIT_ASSERT(memcmp(" / HTTP/1.0\n", &output.buf[output.req_start],(output.req_end-output.req_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.m_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.m_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.u_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.u_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.v_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.v_end);
    CPPUNIT_ASSERT_EQUAL(0, output.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.v_min);
    input.reset();

    // binary code in method (strange but ...)
    input.append("GET\x0B / HTTP/1.1\n", 16);
    //printf("TEST: %d-%d/%d '%.*s'\n", output.req_start, output.req_end, input.contentSize(), 16, input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_OK, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req_start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req_end);
    CPPUNIT_ASSERT(memcmp("GET\x0B / HTTP/1.1\n", &output.buf[output.req_start],(output.req_end-output.req_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.m_start);
    CPPUNIT_ASSERT_EQUAL(3, output.m_end);
    CPPUNIT_ASSERT(memcmp("GET\x0B", &output.buf[output.m_start],(output.m_end-output.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(5, output.u_start);
    CPPUNIT_ASSERT_EQUAL(5, output.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.u_start],(output.u_end-output.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(7, output.v_start);
    CPPUNIT_ASSERT_EQUAL(14, output.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/1.1", &output.buf[output.v_start],(output.v_end-output.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(1, output.v_maj);
    CPPUNIT_ASSERT_EQUAL(1, output.v_min);
    input.reset();

    // CR in method
