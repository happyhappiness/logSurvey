            printf("%c", anEntry->_appended_text[i] );
        }
        /* make this an int comparison, so that we can see the ASCII code at failure */
        CPPUNIT_ASSERT_EQUAL( (int)(expect[i]), (int)anEntry->_appended_text[i] );
    }
    printf("\n");
    CPPUNIT_ASSERT_EQUAL( expect, anEntry->_appended_text);
