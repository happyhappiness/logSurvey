#include <math.h>
#include <net/if.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#define DEBUG(...) printf(__VA_ARGS__)

static _Bool is_multicast(struct addrinfo const *ai) {
  if (ai->ai_family == AF_INET) {
    struct sockaddr_in *addr = (struct sockaddr_in *)ai->ai_addr;
