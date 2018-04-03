    CPPUNIT_ASSERT_EQUAL(9, output.req.v_min);
    input.reset();

    // no version
    input.append("GET / HTTP/\n", 12);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(10, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // no major version
    input.append("GET / HTTP/.1\n", 14);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/.1\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(12, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/.1", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // no version dot
    input.append("GET / HTTP/11\n", 14);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/11\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(12, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/11", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // negative major version (bug 3062)
    input.append("GET / HTTP/-999999.1\n", 21);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/-999999.1\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(19, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/-999999.1", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // no minor version
    input.append("GET / HTTP/1.\n", 14);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/1.\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(12, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/1.", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // negative major version (bug 3062 corollary)
    input.append("GET / HTTP/1.-999999\n", 21);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_HTTP_VERSION_NOT_SUPPORTED, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/1.-999999\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(6, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(19, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/1.-999999", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // binary line
    input.append("\xB\xC\xE\xF\n", 5);
    //printf("TEST: binary-line\n");
