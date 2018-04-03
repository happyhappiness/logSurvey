    AnyP::ProtocolVersion version;
};

static void
testResults(int line, const SBuf &input, Http1::RequestParser &output, struct resultSet &expect)
{
#if WHEN_TEST_DEBUG_IS_NEEDED
    printf("TEST @%d, in=%u: " SQUIDSBUFPH "\n", line, input.length(), SQUIDSBUFPRINT(input));
#endif

    // runs the parse
    CPPUNIT_ASSERT_EQUAL(expect.parsed, output.parse(input));

    // check easily visible field outputs
    CPPUNIT_ASSERT_EQUAL(expect.method, output.method_);
    if (expect.uri != NULL)
        CPPUNIT_ASSERT_EQUAL(0, output.uri_.cmp(expect.uri));
    CPPUNIT_ASSERT_EQUAL(expect.version, output.msgProtocol_);
    CPPUNIT_ASSERT_EQUAL(expect.status, output.parseStatusCode);

    // check more obscure states
