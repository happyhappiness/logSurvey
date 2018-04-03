 
     Ip::Address bnIPA = "2000:800::45";
 
+//char test[256];
+//bnIPA.NtoA(test, 256);
+//printf("bnIPA: %s\n", test);
+
     /* test stored values */
     CPPUNIT_ASSERT( !bnIPA.IsAnyAddr() );
     CPPUNIT_ASSERT( !bnIPA.IsNoAddr() );
