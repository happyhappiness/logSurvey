    CPPUNIT_ASSERT_EQUAL(9, output.req.v_min);
    input.reset();

    // binary line
    input.append("\xB\xC\xE\xF\n", 5);
    //printf("TEST: binary-line\n");
