                  res == test_array[i].result
                  && (res == false 
                      || 0 == strcmp (test_array[i].filename, filename)));
-
-      /* printf ("test %d: %s\n", i, res == false ? "false" : filename); */
     }
 
   return NULL;
