 * Returns zero on success
 * Returns non-zero on error
 */
static int net_send(int *sockfd, const char *buff, int len) {
  uint16_t packet_size;

  assert(len > 0);
  assert(*sockfd >= 0);

  /* send short containing size of data packet */
  packet_size = htons((uint16_t)len);

  if (swrite(*sockfd, (void *)&packet_size, sizeof(packet_size)) != 0) {
    close(*sockfd);
    *sockfd = -1;
    return (-1);
  }

  /* send data packet */
  if (swrite(*sockfd, (void *)buff, len) != 0) {
    close(*sockfd);
    *sockfd = -1;
    return (-2);
  }

  return (0);
}

/* Get and print status from apcupsd NIS server */
static int apc_query_server(char const *node, char const *service,
                            apc_detail_t *apcups_detail) {
  int n;
  char recvline[1024];
  char *tokptr;
  char *toksaveptr;
  _Bool retry = 1;
  int status;

#if APCMAIN
#define PRINT_VALUE(name, val)                                                 \
  printf("  Found property: name = %s; value = %f;\n", name, val)
#else
#define PRINT_VALUE(name, val) /**/
#endif

  while (retry) {
    if (global_sockfd < 0) {
      global_sockfd = net_open(node, service);
      if (global_sockfd < 0) {
        ERROR("apcups plugin: Connecting to the "
              "apcupsd failed.");
        return (-1);
      }
    }

    status = net_send(&global_sockfd, "status", strlen("status"));
    if (status != 0) {
      /* net_send is closing the socket on error. */
      assert(global_sockfd < 0);
      if (retry) {
        retry = 0;
        count_retries++;
        continue;
      }

      ERROR("apcups plugin: Writing to the socket failed.");
      return (-1);
    }

    break;
  } /* while (retry) */

  /* When collectd's collection interval is larger than apcupsd's
   * timeout, we would have to retry / re-connect each iteration. Try to
   * detect this situation and shut down the socket gracefully in that
   * case. Otherwise, keep the socket open to avoid overhead. */
  count_iterations++;
  if ((count_iterations == 10) && (count_retries > 2)) {
    NOTICE("apcups plugin: There have been %i retries in the "
           "first %i iterations. Will close the socket "
           "in future iterations.",
           count_retries, count_iterations);
    conf_persistent_conn = 0;
  }

  while ((n = net_recv(&global_sockfd, recvline, sizeof(recvline) - 1)) > 0) {
    assert((size_t)n < sizeof(recvline));
    recvline[n] = 0;
#if APCMAIN
    printf("net_recv = `%s';\n", recvline);
#endif /* if APCMAIN */

    toksaveptr = NULL;
    tokptr = strtok_r(recvline, " :\t", &toksaveptr);
    while (tokptr != NULL) {
      char *key = tokptr;
      if ((tokptr = strtok_r(NULL, " :\t", &toksaveptr)) == NULL)
        continue;

      gauge_t value;
      if (strtogauge(tokptr, &value) != 0)
        continue;

      PRINT_VALUE(key, value);

      if (strcmp("LINEV", key) == 0)
        apcups_detail->linev = value;
      else if (strcmp("BATTV", key) == 0)
        apcups_detail->battv = value;
      else if (strcmp("ITEMP", key) == 0)
        apcups_detail->itemp = value;
      else if (strcmp("LOADPCT", key) == 0)
        apcups_detail->loadpct = value;
      else if (strcmp("BCHARGE", key) == 0)
        apcups_detail->bcharge = value;
      else if (strcmp("OUTPUTV", key) == 0)
        apcups_detail->outputv = value;
      else if (strcmp("LINEFREQ", key) == 0)
        apcups_detail->linefreq = value;
      else if (strcmp("TIMELEFT", key) == 0) {
        /* Convert minutes to seconds if requested by
         * the user. */
        if (conf_report_seconds)
          value *= 60.0;
        apcups_detail->timeleft = value;
      }

      tokptr = strtok_r(NULL, ":", &toksaveptr);
    } /* while (tokptr != NULL) */
  }
  status = errno; /* save errno, net_shutdown() may re-set it. */

  if (!conf_persistent_conn)
    net_shutdown(&global_sockfd);

  if (n < 0) {
    char errbuf[1024];
    ERROR("apcups plugin: Reading from socket failed: %s",
          sstrerror(status, errbuf, sizeof(errbuf)));
    return (-1);
  }

  return (0);
}

static int apcups_config(oconfig_item_t *ci) {
  _Bool persistent_conn_set = 0;

  for (int i = 0; i < ci->children_num; i++) {
    oconfig_item_t *child = ci->children + i;

    if (strcasecmp(child->key, "Host") == 0)
      cf_util_get_string(child, &conf_node);
    else if (strcasecmp(child->key, "Port") == 0)
      cf_util_get_service(child, &conf_service);
    else if (strcasecmp(child->key, "ReportSeconds") == 0)
      cf_util_get_boolean(child, &conf_report_seconds);
    else if (strcasecmp(child->key, "PersistentConnection") == 0) {
      cf_util_get_boolean(child, &conf_persistent_conn);
      persistent_conn_set = 1;
    } else
      ERROR("apcups plugin: Unknown config option \"%s\".", child->key);
  }

  if (!persistent_conn_set) {
    double interval = CDTIME_T_TO_DOUBLE(plugin_get_interval());
    if (interval > APCUPS_SERVER_TIMEOUT) {
      NOTICE("apcups plugin: Plugin poll interval set to %.3f seconds. "
             "Apcupsd NIS socket timeout is %.3f seconds, "
             "PersistentConnection disabled by default.",
             interval, APCUPS_SERVER_TIMEOUT);
      conf_persistent_conn = 0;
    }
  }

  return (0);
} /* int apcups_config */

static void apc_submit_generic(const char *type, const char *type_inst,
                               gauge_t value) {
  value_t values[1];
  value_list_t vl = VALUE_LIST_INIT;

  if (isnan(value))
    return;

  values[0].gauge = value;

  vl.values = values;
  vl.values_len = 1;
  sstrncpy(vl.host, hostname_g, sizeof(vl.host));
  sstrncpy(vl.plugin, "apcups", sizeof(vl.plugin));
  sstrncpy(vl.plugin_instance, "", sizeof(vl.plugin_instance));
  sstrncpy(vl.type, type, sizeof(vl.type));
  sstrncpy(vl.type_instance, type_inst, sizeof(vl.type_instance));

  plugin_dispatch_values(&vl);
}

static void apc_submit(apc_detail_t const *apcups_detail) {
  apc_submit_generic("voltage", "input", apcups_detail->linev);
  apc_submit_generic("voltage", "output", apcups_detail->outputv);
  apc_submit_generic("voltage", "battery", apcups_detail->battv);
  apc_submit_generic("charge", "", apcups_detail->bcharge);
  apc_submit_generic("percent", "load", apcups_detail->loadpct);
  apc_submit_generic("timeleft", "", apcups_detail->timeleft);
  apc_submit_generic("temperature", "", apcups_detail->itemp);
  apc_submit_generic("frequency", "input", apcups_detail->linefreq);
}

static int apcups_read(void) {
  apc_detail_t apcups_detail = {
      .linev = NAN,
      .outputv = NAN,
      .battv = NAN,
      .loadpct = NAN,
      .bcharge = NAN,
      .timeleft = NAN,
      .itemp = NAN,
      .linefreq = NAN,
  };

  int status =
      apc_query_server(conf_node == NULL ? APCUPS_DEFAULT_NODE : conf_node,
                       conf_service, &apcups_detail);
  if (status != 0) {
    DEBUG("apcups plugin: apc_query_server (\"%s\", \"%s\") = %d",
          conf_node == NULL ? APCUPS_DEFAULT_NODE : conf_node, conf_service,
          status);
    return (status);
  }

  apc_submit(&apcups_detail);

  return (0);
} /* apcups_read */

void module_register(void) {
  plugin_register_complex_config("apcups", apcups_config);
  plugin_register_read("apcups", apcups_read);
  plugin_register_shutdown("apcups", apcups_shutdown);
} /* void module_register */
