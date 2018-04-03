     }
 
     // tab padded method (NP: tab is not SP so treated as any other binary)
+    // XXX: binary codes are non-compliant
     {
         input.append("\tGET / HTTP/1.1\n", 16);
         //printf("TEST: '%s'\n",input.content());
         output.reset(input.content(), input.contentSize());
         CPPUNIT_ASSERT_EQUAL(false, output.parse());
         CPPUNIT_ASSERT_EQUAL(false, output.isDone());
-        CPPUNIT_ASSERT_EQUAL(Http1::HTTP_PARSE_FIRST, output.completedState_);
+        CPPUNIT_ASSERT_EQUAL(Http1::HTTP_PARSE_MIME, output.parsingStage_);
         CPPUNIT_ASSERT_EQUAL(Http::scOkay, output.request_parse_status);
         CPPUNIT_ASSERT_EQUAL(0, output.req.start);
         CPPUNIT_ASSERT_EQUAL((int)input.contentSize()-1, output.req.end);
