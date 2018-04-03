    CPPUNIT_ASSERT_EQUAL(0, output.v_min);
    input.reset();

    // no minor version
    input.append("GET / HTTP/1.\n", 14);
    //printf("TEST: '%s'\n",input.content());
