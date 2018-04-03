     printf("Actual Text:\n");
     /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
     for ( int i = 0; i < anEntry->_appended_text.size(); i++) {
-        CPPUNIT_ASSERT( expect.buf()[i] );
-        CPPUNIT_ASSERT( anEntry->_appended_text.buf()[i] );
+        CPPUNIT_ASSERT( expect[i] );
+        CPPUNIT_ASSERT( anEntry->_appended_text[i] );
 
         /* slight hack to make special chars visible */
-        switch (anEntry->_appended_text.buf()[i]) {
+        switch (anEntry->_appended_text[i]) {
         case '\t':
             printf("\\t");
             break;
         default:
-            printf("%c", anEntry->_appended_text.buf()[i] );
+            printf("%c", anEntry->_appended_text[i] );
         }
         /* make this an int comparison, so that we can see the ASCII code at failure */
-        CPPUNIT_ASSERT_EQUAL( (int)expect.buf()[i], (int)anEntry->_appended_text.buf()[i] );
+        CPPUNIT_ASSERT_EQUAL( (int)(expect[i]), (int)anEntry->_appended_text[i] );
     }
     printf("\n");
     CPPUNIT_ASSERT_EQUAL( expect, anEntry->_appended_text);
