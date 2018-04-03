     printf("Actual Text:\n");
     /* TODO: these should really be just [] lookups, but String doesn't have those here yet. */
     for ( int i = 0; i < anEntry->_appended_text.size(); i++) {
-        CPPUNIT_ASSERT( expect.unsafeBuf()[i] );
-        CPPUNIT_ASSERT( anEntry->_appended_text.unsafeBuf()[i] );
+        CPPUNIT_ASSERT( expect[i] );
+        CPPUNIT_ASSERT( anEntry->_appended_text[i] );
 
         /* slight hack to make special chars visible */
-        switch (anEntry->_appended_text.unsafeBuf()[i]) {
+        switch (anEntry->_appended_text[i]) {
         case '\t':
             printf("\\t");
             break;
         default:
-            printf("%c", anEntry->_appended_text.unsafeBuf()[i] );
+            printf("%c", anEntry->_appended_text[i] );
         }
         /* make this an int comparison, so that we can see the ASCII code at failure */
         CPPUNIT_ASSERT_EQUAL( (int)expect.unsafeBuf()[i], (int)anEntry->_appended_text.unsafeBuf()[i] );