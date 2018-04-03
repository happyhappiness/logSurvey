          token on the next line. */
       if (remaining_chars <= strlen (token)) 
         {
-          int j;
-          printf ("\n");
-          j = 0;
-          for (j = 0; j < leading_spaces; j++) 
-            {
-              printf (" ");
-            }
+          printf ("\n%*c", leading_spaces, ' ');
           remaining_chars = line_length - leading_spaces;
         }
       printf ("%s ", token);
