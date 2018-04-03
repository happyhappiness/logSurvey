 
 #ifdef TEST
   /* When testing this code, it is useful to know the length returned */
-  printf("Input length = %d, actual = %d\n",
-      bufdesc.dsc$w_length, buffer_length);
+  printf ("Input length = %d, actual = %u\n",
+          bufdesc.dsc$w_length, buffer_length);
 #endif
 
   /* Conversion from VMS time to C time.
