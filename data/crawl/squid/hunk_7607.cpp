 #ifdef REMOVE_OBJECT
     printf("<OPTION VALUE=\"remove\">Remove Object (URL required)\n");
 #endif
-    printf("</SELECT>\n");
-    printf("</PRE>\n");
+    printf("</SELECT>\n\n");
     printf("<HR>\n");
-    printf("<BR><INPUT TYPE=\"submit\"> <INPUT TYPE=\"reset\">\n");
-    printf("</FORM>\n");
+    printf("<INPUT TYPE=\"submit\"> <INPUT TYPE=\"reset\">\n");
+    printf("</FORM></PRE>\n");
     print_trailer();
 }
 
