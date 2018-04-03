    CPPUNIT_ASSERT_EQUAL(0, output.v_min);
    input.reset();

    // binary line
    input.append("\xB\xC\xE\xF\n", 5);
    //printf("TEST: binary-line\n");