       break;
   } /* for (i = 0; i < ci->children_num; i++) */
 
-  /* TODO: Validate the struct. */
+  assert (data.name != NULL);
+  if (data.type[0] == 0)
+  {
+    ERROR ("Modbus plugin: Data block \"%s\": No type has been specified.",
+        data.name);
+    status = -1;
+  }
+
+  if (status == 0)
+    data_copy (&data_definitions, &data);
 
-  data_copy (&data_definitions, &data);
   sfree (data.name);
 
-  return (0);
+  return (status);
 } /* }}} int mb_config_add_data */
 
-static void mb_free_internal (mb_internal_t *i) /* {{{ */
+static int mb_config_set_host_address (mb_host_t *host, /* {{{ */
+    const char *address)
 {
-  if (i == NULL)
-    return;
+  struct addrinfo *ai_list;
+  struct addrinfo *ai_ptr;
+  struct addrinfo  ai_hints;
+  int status;
 
-  free (i->connection);
-  free (i);
-} /* }}} void mb_free_internal */
+  if ((host == NULL) || (address == NULL))
+    return (EINVAL);
 
-static mb_internal_t *mb_alloc_internal (void) /* {{{ */
-{
-  mb_internal_t *ret;
+  memset (&ai_hints, 0, sizeof (ai_hints));
+#if AI_ADDRCONFIG
+  ai_hints.ai_flags |= AI_ADDRCONFIG;
+#endif
+  /* XXX: libmodbus can only handle IPv4 addresses. */
+  ai_hints.ai_family = AF_INET;
+  ai_hints.ai_addr = NULL;
+  ai_hints.ai_canonname = NULL;
+  ai_hints.ai_next = NULL;
+
+  ai_list = NULL;
+  status = getaddrinfo (address, /* service = */ NULL,
+      &ai_hints, &ai_list);
+  if (status != 0)
+  {
+    char errbuf[1024];
+    ERROR ("Modbus plugin: getaddrinfo failed: %s",
+        (status == EAI_SYSTEM)
+        ? sstrerror (errno, errbuf, sizeof (errbuf))
+        : gai_strerror (status));
+    return (status);
+  }
 
-  ret = malloc (sizeof (*ret));
-  if (ret == NULL)
-    return (NULL);
-  memset (ret, 0, sizeof (*ret));
+  for (ai_ptr = ai_list; ai_ptr != NULL; ai_ptr = ai_ptr->ai_next)
+  {
+    status = getnameinfo (ai_ptr->ai_addr, ai_ptr->ai_addrlen,
+        host->node, sizeof (host->node),
+        /* service = */ NULL, /* length = */ 0,
+        /* flags = */ NI_NUMERICHOST);
+    if (status == 0)
+      break;
+  } /* for (ai_ptr) */
 
-  ret->connection = calloc (1, sizeof (*ret->connection));
-  if (ret->connection == NULL)
+  freeaddrinfo (ai_list);
+
+  if (status != 0)
+    ERROR ("Modbus plugin: Unable to translate node name: \"%s\"", address);
+  else /* if (status == 0) */
   {
-    mb_free_internal (ret);
-    return (NULL);
+    DEBUG ("Modbus plugin: mb_config_set_host_address: %s -> %s",
+        address, host->node);
   }
 
-  return (ret);
-} /* }}} mb_internal_t *mb_alloc_internal */
+  return (status);
+} /* }}} int mb_config_set_host_address */
 
-static mb_internal_t *mb_init (void) /* {{{ */
+static int mb_config_add_slave (mb_host_t *host, oconfig_item_t *ci) /* {{{ */
 {
-  mb_internal_t *ret;
+  mb_slave_t *slave;
   int status;
+  int i;
 
-  ret = mb_alloc_internal ();
-  if (ret == NULL)
-    return (NULL);
+  if ((host == NULL) || (ci == NULL))
+    return (EINVAL);
 
-  modbus_set_debug (ret->connection, 1);
+  slave = realloc (host->slaves, sizeof (*slave) * (host->slaves_num + 1));
+  if (slave == NULL)
+    return (ENOMEM);
+  host->slaves = slave;
+  slave = host->slaves + host->slaves_num;
+  memset (slave, 0, sizeof (*slave));
+  slave->collect = NULL;
 
-  /* We'll do the error handling ourselves. */
-  modbus_set_error_handling (ret->connection, NOP_ON_ERROR);
+  status = cf_util_get_int (ci, &slave->id);
+  if (status != 0)
+    return (status);
+
+  for (i = 0; i < ci->children_num; i++)
+  {
+    oconfig_item_t *child = ci->children + i;
+    status = 0;
+
+    if (strcasecmp ("Instance", child->key) == 0)
+      status = cf_util_get_string_buffer (child,
+          slave->instance, sizeof (slave->instance));
+    else if (strcasecmp ("Collect", child->key) == 0)
+    {
+      char buffer[1024];
+      status = cf_util_get_string_buffer (child, buffer, sizeof (buffer));
+      if (status == 0)
+        data_copy_by_name (&slave->collect, data_definitions, buffer);
+      status = 0; /* continue after failure. */
+    }
+    else
+    {
+      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
+      status = -1;
+    }
 
-  modbus_init_tcp (ret->connection,
-      /* host = */ "172.18.20.30", /* FIXME: Only IP adresses allowed. -> convert hostnames. */
-      /* post = */ MODBUS_TCP_DEFAULT_PORT); /* FIXME: Use configured port. */
+    if (status != 0)
+      break;
+  }
+
+  if ((status == 0) && (slave->collect == NULL))
+    status = EINVAL;
+
+  if (slave->id < 0)
+    status = EINVAL;
 
-  status = modbus_connect (ret->connection);
-  printf ("mb_init: modbus_connect returned status %i\n", status);
+  if (status == 0)
+    host->slaves_num++;
+  else /* if (status != 0) */
+    data_free_all (slave->collect);
+
+  return (status);
+} /* }}} int mb_config_add_slave */
+
+static int mb_config_add_host (oconfig_item_t *ci) /* {{{ */
+{
+  mb_host_t *host;
+  int status;
+  int i;
+
+  host = malloc (sizeof (*host));
+  if (host == NULL)
+    return (ENOMEM);
+  memset (host, 0, sizeof (*host));
+  host->slaves = NULL;
+
+  status = cf_util_get_string_buffer (ci, host->host, sizeof (host->host));
   if (status != 0)
+    return (status);
+  if (host->host[0] == 0)
+    return (EINVAL);
+
+  for (i = 0; i < ci->children_num; i++)
   {
-    mb_free_internal (ret);
-    return (NULL);
+    oconfig_item_t *child = ci->children + i;
+    status = 0;
+
+    if (strcasecmp ("Address", child->key) == 0)
+    {
+      char buffer[NI_MAXHOST];
+      status = cf_util_get_string_buffer (child, buffer, sizeof (buffer));
+      if (status == 0)
+        status = mb_config_set_host_address (host, buffer);
+    }
+    else if (strcasecmp ("Port", child->key) == 0)
+    {
+      host->port = cf_util_get_port_number (child);
+      if (host->port <= 0)
+        status = -1;
+    }
+    else if (strcasecmp ("Interval", child->key) == 0)
+      status = cf_util_get_int (child, &host->interval);
+    else if (strcasecmp ("Slave", child->key) == 0)
+      /* Don't set status: Gracefully continue if a slave fails. */
+      mb_config_add_slave (host, child);
+    else
+    {
+      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
+      status = -1;
+    }
+
+    if (status != 0)
+      break;
+  } /* for (i = 0; i < ci->children_num; i++) */
+
+  assert (host->host[0] != 0);
+  if (host->host[0] == 0)
+  {
+    ERROR ("Modbus plugin: Data block \"%s\": No type has been specified.",
+        host->host);
+    status = -1;
   }
 
-  return (ret);
-} /* }}} mb_internal_t *mb_init */
+  if (status == 0)
+  {
+    user_data_t ud;
+    char name[1024];
+    struct timespec interval;
+
+    ud.data = host;
+    ud.free_func = host_free;
 
-static float mb_register_to_float (uint16_t hi, uint16_t lo) /* {{{ */
+    ssnprintf (name, sizeof (name), "modbus-%s", host->host);
+
+    interval.tv_nsec = 0;
+    if (host->interval > 0)
+      interval.tv_sec = host->interval;
+    else
+      interval.tv_sec = 0;
+
+    plugin_register_complex_read (name, mb_read,
+        (interval.tv_sec > 0) ? &interval : NULL,
+        &ud);
+  }
+  else
+  {
+    host_free (host);
+  }
+
+  return (status);
+} /* }}} int mb_config_add_host */
+
+static int mb_config (oconfig_item_t *ci) /* {{{ */
 {
-  union
+  int i;
+
+  if (ci == NULL)
+    return (EINVAL);
+
+  for (i = 0; i < ci->children_num; i++)
   {
-    uint8_t b[4];
-    float f;
-  } conv;
+    oconfig_item_t *child = ci->children + i;
 
-#if 1
-  /* little endian */
-  conv.b[0] = lo & 0x00ff;
-  conv.b[1] = (lo >> 8) & 0x00ff;
-  conv.b[2] = hi & 0x00ff;
-  conv.b[3] = (hi >> 8) & 0x00ff;
-#else
-  conv.b[3] = lo & 0x00ff;
-  conv.b[2] = (lo >> 8) & 0x00ff;
-  conv.b[1] = hi & 0x00ff;
-  conv.b[0] = (hi >> 8) & 0x00ff;
-#endif
+    if (strcasecmp ("Data", child->key) == 0)
+      mb_config_add_data (child);
+    else if (strcasecmp ("Host", child->key) == 0)
+      mb_config_add_host (child);
+    else
+      ERROR ("Modbus plugin: Unknown configuration option: %s", child->key);
+  }
 
-  return (conv.f);
-} /* }}} float mb_register_to_float */
+  return (0);
+} /* }}} int mb_config */
+
+/* ========= */
 
-static int mb_read (mb_internal_t *dev, int register_addr, _Bool is_float) /* {{{ */
+#if 0
+static int foo (void) /* {{{ */
 {
   int status;
   uint16_t values[2];
