             snprintf(bytestr, sizeof(bytestr), "%c", c);
             strncat(charstr, bytestr, sizeof(charstr)-strlen(charstr)-1);
 
-            if(n%16 == 0) { 
+            if (n%16 == 0) {
                 /* line completed */
                 fprintf(stderr, "[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
                 hexstr[0] = 0;
                 charstr[0] = 0;
-            } else if(n%8 == 0) {
+            } else if (n%8 == 0) {
                 /* half line: add whitespaces */
                 strncat(hexstr, "  ", sizeof(hexstr)-strlen(hexstr)-1);
                 strncat(charstr, " ", sizeof(charstr)-strlen(charstr)-1);
