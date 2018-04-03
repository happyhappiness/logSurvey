    CPPUNIT_ASSERT_EQUAL(0, output.req.v_min);
    input.reset();

    // RFC 2616 : . method
    input.append(". / HTTP/1.1\n", 13);
    //printf("TEST: '%s'\n",input.content());
