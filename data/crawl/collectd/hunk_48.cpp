 #endif
 
 #include "collectd/lcc_features.h"
+#include "collectd/network_parse.h" /* for lcc_network_parse_options_t */
 #include "collectd/server.h"
 
-#include <arpa/inet.h>
-#include <endian.h>
 #include <errno.h>
-#include <inttypes.h>
-#include <math.h>
 #include <net/if.h>
 #include <netdb.h>
-#include <pthread.h>
-#include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
 
-#define GCRYPT_NO_DEPRECATED
-#include <gcrypt.h>
-
 #include <stdio.h>
 #define DEBUG(...) printf(__VA_ARGS__)
 
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
-
-/* forward declaration because parse_sign_sha256()/parse_encrypt_aes256() and
- * network_parse() need to call each other. */
-static int network_parse(void *data, size_t data_size, lcc_security_level_t sl,
-                         lcc_network_parse_options_t const *opts);
-
 static _Bool is_multicast(struct addrinfo const *ai) {
   if (ai->ai_family == AF_INET) {
     struct sockaddr_in *addr = (struct sockaddr_in *)ai->ai_addr;
