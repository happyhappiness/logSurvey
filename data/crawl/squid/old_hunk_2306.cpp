    CPPUNIT_ASSERT_EQUAL(12, output.req.v_min);
    input.reset();

    // space padded URL
    input.append("GET  /     HTTP/1.1\r\n", 21);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_OK, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET  /     HTTP/1.1\r\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(5, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(5, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(11, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(18, output.req.v_end);
    CPPUNIT_ASSERT(memcmp("HTTP/1.1", &output.buf[output.req.v_start],(output.req.v_end-output.req.v_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_min);
    input.reset();

    // space padded version
    // RFC 1945 and 2616 specify version is followed by CRLF. No intermediary bytes.
    // NP: the terminal whitespace is a special case: invalid for even HTTP/0.9 with no version tag
    input.append("GET / HTTP/1.1 \n", 16);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_BAD_REQUEST, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET / HTTP/1.1 \n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(2, output.req.m_end);
    CPPUNIT_ASSERT(memcmp("GET", &output.buf[output.req.m_start],(output.req.m_end-output.req.m_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(4, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(13, output.req.u_end);
    CPPUNIT_ASSERT(memcmp("/ HTTP/1.1", &output.buf[output.req.u_start],(output.req.u_end-output.req.u_start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_end);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // whitespace inside URI. (nasty but happens)
    input.append("GET /fo o/ HTTP/1.1\n", 20);
    //printf("TEST: '%s'\n",input.content());
