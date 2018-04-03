      break;
  } /* for (i = 0; i < ci->children_num; i++) */

  assert (data.name != NULL);
  if (data.type[0] == 0)
  {
    ERROR ("Modbus plugin: Data block \"%s\": No type has been specified.",
        data.name);
    status = -1;
  }

  if (status == 0)
    data_copy (&data_definitions, &data);

  sfree (data.name);

  return (status);
} /* }}} int mb_config_add_data */

static int mb_config_set_host_address (mb_host_t *host, /* {{{ */
    const char *address)
{
  struct addrinfo *ai_list;
  struct addrinfo *ai_ptr;
  struct addrinfo  ai_hints;
  int status;

  if ((host == NULL) || (address == NULL))
    return (EINVAL);

  memset (&ai_hints, 0, sizeof (ai_hints));
#if AI_ADDRCONFIG
  ai_hints.ai_flags |= AI_ADDRCONFIG;
#endif
  /* XXX: libmodbus can only handle IPv4 addresses. */
  ai_hints.ai_family = AF_INET;
  ai_hints.ai_addr = NULL;
  ai_hints.ai_canonname = NULL;
  ai_hints.ai_next = NULL;

  ai_list = NULL;
  status = getaddrinfo (address, /* service = */ NULL,
      &ai_hints, &ai_list);
  if (status != 0)
  {
    char errbuf[1024];
    ERROR ("Modbus plugin: getaddrinfo failed: %s",
        (status == EAI_SYSTEM)
        ? sstrerror (errno, errbuf, sizeof (errbuf))
        : gai_strerror (status));
    return (status);
  }

  for (ai_ptr = ai_list; ai_ptr != NULL; ai_ptr = ai_ptr->ai_next)
  {
    status = getnameinfo (ai_ptr->ai_addr, ai_ptr->ai_addrlen,
        host->node, sizeof (host->node),
        /* service = */ NULL, /* length = */ 0,
        /* flags = */ NI_NUMERICHOST);
    if (status == 0)
      break;
  } /* for (ai_ptr) */

  freeaddrinfo (ai_list);

  if (status != 0)
    ERROR ("Modbus plugin: Unable to translate node name: \"%s\"", address);
  else /* if (status == 0) */
  {
    DEBUG ("Modbus plugin: mb_config_set_host_address: %s -> %s",
        address, host->node);
  }

  return (status);
} /* }}} int mb_config_set_host_address */

static int mb_config_add_slave (mb_host_t *host, oconfig_item_t *ci) /* {{{ */
{
  mb_slave_t *slave;
  int status;
  int i;

  if ((host == NULL) || (ci == NULL))
    return (EINVAL);

  slave = realloc (host->slaves, sizeof (*slave) * (host->slaves_num + 1));
  if (slave == NULL)
    return (ENOMEM);
  host->slaves = slave;
  slave = host->slaves + host->slaves_num;
  memset (slave, 0, sizeof (*slave));
  slave->collect = NULL;

  status = cf_util_get_int (ci, &slave->id);
  if (status != 0)
    return (status);

  for (i = 0; i < ci->children_num; i++)
  {
    oconfig_item_t *child = ci->children + i;
    status = 0;

    if (strcasecmp ("Instance", child->key) == 0)
      status = cf_util_get_string_buffer (child,
          slave->instance, sizeof (slave->instance));
    else if (strcasecmp ("Collect", child->key) == 0)
    {
      char buffer[1024];
      status = cf_util_get_string_buffer (child, buffer, sizeof (buffer));
      if (status == 0)
        data_copy_by_name (&slave->collect, data_definitions, buffer);
      status = 0; /* continue after failure. */
    }
    else
    {
      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
      status = -1;
    }

    if (status != 0)
      break;
  }

  if ((status == 0) && (slave->collect == NULL))
    status = EINVAL;

  if (slave->id < 0)
    status = EINVAL;

  if (status == 0)
    host->slaves_num++;
  else /* if (status != 0) */
    data_free_all (slave->collect);

  return (status);
} /* }}} int mb_config_add_slave */

static int mb_config_add_host (oconfig_item_t *ci) /* {{{ */
{
  mb_host_t *host;
  int status;
  int i;

  host = malloc (sizeof (*host));
  if (host == NULL)
    return (ENOMEM);
  memset (host, 0, sizeof (*host));
  host->slaves = NULL;

  status = cf_util_get_string_buffer (ci, host->host, sizeof (host->host));
  if (status != 0)
    return (status);
  if (host->host[0] == 0)
    return (EINVAL);

  for (i = 0; i < ci->children_num; i++)
  {
    oconfig_item_t *child = ci->children + i;
    status = 0;

    if (strcasecmp ("Address", child->key) == 0)
    {
      char buffer[NI_MAXHOST];
      status = cf_util_get_string_buffer (child, buffer, sizeof (buffer));
      if (status == 0)
        status = mb_config_set_host_address (host, buffer);
    }
    else if (strcasecmp ("Port", child->key) == 0)
    {
      host->port = cf_util_get_port_number (child);
      if (host->port <= 0)
        status = -1;
    }
    else if (strcasecmp ("Interval", child->key) == 0)
      status = cf_util_get_int (child, &host->interval);
    else if (strcasecmp ("Slave", child->key) == 0)
      /* Don't set status: Gracefully continue if a slave fails. */
      mb_config_add_slave (host, child);
    else
    {
      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
      status = -1;
    }

    if (status != 0)
      break;
  } /* for (i = 0; i < ci->children_num; i++) */

  assert (host->host[0] != 0);
  if (host->host[0] == 0)
  {
    ERROR ("Modbus plugin: Data block \"%s\": No type has been specified.",
        host->host);
    status = -1;
  }

  if (status == 0)
  {
    user_data_t ud;
    char name[1024];
    struct timespec interval;

    ud.data = host;
    ud.free_func = host_free;

    ssnprintf (name, sizeof (name), "modbus-%s", host->host);

    interval.tv_nsec = 0;
    if (host->interval > 0)
      interval.tv_sec = host->interval;
    else
      interval.tv_sec = 0;

    plugin_register_complex_read (name, mb_read,
        (interval.tv_sec > 0) ? &interval : NULL,
        &ud);
  }
  else
  {
    host_free (host);
  }

  return (status);
} /* }}} int mb_config_add_host */

static int mb_config (oconfig_item_t *ci) /* {{{ */
{
  int i;

  if (ci == NULL)
    return (EINVAL);

  for (i = 0; i < ci->children_num; i++)
  {
    oconfig_item_t *child = ci->children + i;

    if (strcasecmp ("Data", child->key) == 0)
      mb_config_add_data (child);
    else if (strcasecmp ("Host", child->key) == 0)
      mb_config_add_host (child);
    else
      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
  }

  return (0);
} /* }}} int mb_config */

/* ========= */

#if 0
static int foo (void) /* {{{ */
{
  int status;
  uint16_t values[2];
