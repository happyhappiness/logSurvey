       switch (*p)
         {
         case '$':
-          /* $$ seen means output one $ to the variable output buffer.  */
-          o = variable_buffer_output (o, p, 1);
+        case '\0':
+          /* $$ or $ at the end of the string means output one $ to the
+             variable output buffer.  */
+          o = variable_buffer_output (o, p1, 1);
           break;
 
         case '(':
