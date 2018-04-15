 
   return 0;
 }
+#endif
 
 int main(void) {
   int ret = 0;
 
-  printf("libcollectdclient/server_test.c\n");
-
   int status;
   if ((status = test_network_parse())) {
     ret = status;
