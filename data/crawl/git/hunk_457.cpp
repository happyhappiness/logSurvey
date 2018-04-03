 	ihvout[0] = ihvin[0] + a; ihvout[1] = ihvin[1] + b; ihvout[2] = ihvin[2] + c; ihvout[3] = ihvin[3] + d; ihvout[4] = ihvin[4] + e; \
 }
 
+#ifdef _MSC_VER
+#pragma warning(push)
+#pragma warning(disable: 4127)  /* Complier complains about the checks in the above macro being constant. */
+#endif
+
 #ifdef DOSTORESTATE0
 SHA1_RECOMPRESS(0)
 #endif
