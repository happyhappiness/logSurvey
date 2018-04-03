    CPPUNIT_ASSERT_EQUAL(1, output.req.v_min);
    input.reset();

    // method-only
    input.append("A\n", 2);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_BAD_REQUEST, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("A\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.m_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_end);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    input.append("GET\n", 4);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
    CPPUNIT_ASSERT_EQUAL(-1, HttpParserParseReqLine(&output));
    CPPUNIT_ASSERT_EQUAL(HTTP_BAD_REQUEST, output.request_parse_status);
    CPPUNIT_ASSERT_EQUAL(0, output.req.start);
    CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
    CPPUNIT_ASSERT(memcmp("GET\n", &output.buf[output.req.start],(output.req.end-output.req.start+1)) == 0);
    CPPUNIT_ASSERT_EQUAL(0, output.req.m_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.m_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.u_end);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_start);
    CPPUNIT_ASSERT_EQUAL(-1, output.req.v_end);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // RELAXED space padded method (in strict mode SP is reserved so invalid as a method byte)
