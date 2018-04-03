#endif

#include "collectd/lcc_features.h"
#include "collectd/network_parse.h" /* for lcc_network_parse_options_t */
#include "collectd/server.h"

#include <errno.h>
#include <net/if.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#define DEBUG(...) printf(__VA_ARGS__)

static _Bool is_multicast(struct addrinfo const *ai) {
  if (ai->ai_family == AF_INET) {
    struct sockaddr_in *addr = (struct sockaddr_in *)ai->ai_addr;
