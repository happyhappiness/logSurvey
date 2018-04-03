    CPPUNIT_ASSERT_EQUAL(1, output.req.v_maj);
    CPPUNIT_ASSERT_EQUAL(1, output.req.v_min);
    input.reset();
}

void
testHttpParser::testParseRequestLineInvalid()
{
    // ensure MemPools etc exist
    globalSetup();

    MemBuf input;
    HttpParser output;
    input.init();

    // no method (but in a form which is ambiguous with HTTP/0.9 simple-request)
    // XXX: Bug: HTTP/0.9 requires method to be "GET"
    input.append("/ HTTP/1.0\n", 11);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
