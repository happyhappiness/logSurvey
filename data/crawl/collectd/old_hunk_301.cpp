      break;
  } /* for (i = 0; i < ci->children_num; i++) */

  /* TODO: Validate the struct. */

  data_copy (&data_definitions, &data);
  sfree (data.name);

  return (0);
} /* }}} int mb_config_add_data */

static void mb_free_internal (mb_internal_t *i) /* {{{ */
{
  if (i == NULL)
    return;

  free (i->connection);
  free (i);
} /* }}} void mb_free_internal */

static mb_internal_t *mb_alloc_internal (void) /* {{{ */
{
  mb_internal_t *ret;

  ret = malloc (sizeof (*ret));
  if (ret == NULL)
    return (NULL);
  memset (ret, 0, sizeof (*ret));

  ret->connection = calloc (1, sizeof (*ret->connection));
  if (ret->connection == NULL)
  {
    mb_free_internal (ret);
    return (NULL);
  }

  return (ret);
} /* }}} mb_internal_t *mb_alloc_internal */

static mb_internal_t *mb_init (void) /* {{{ */
{
  mb_internal_t *ret;
  int status;

  ret = mb_alloc_internal ();
  if (ret == NULL)
    return (NULL);

  modbus_set_debug (ret->connection, 1);

  /* We'll do the error handling ourselves. */
  modbus_set_error_handling (ret->connection, NOP_ON_ERROR);

  modbus_init_tcp (ret->connection,
      /* host = */ "172.18.20.30", /* FIXME: Only IP adresses allowed. -> convert hostnames. */
      /* post = */ MODBUS_TCP_DEFAULT_PORT); /* FIXME: Use configured port. */

  status = modbus_connect (ret->connection);
  printf ("mb_init: modbus_connect returned status %i\n", status);
  if (status != 0)
  {
    mb_free_internal (ret);
    return (NULL);
  }

  return (ret);
} /* }}} mb_internal_t *mb_init */

static float mb_register_to_float (uint16_t hi, uint16_t lo) /* {{{ */
{
  union
  {
    uint8_t b[4];
    float f;
  } conv;

#if 1
  /* little endian */
  conv.b[0] = lo & 0x00ff;
  conv.b[1] = (lo >> 8) & 0x00ff;
  conv.b[2] = hi & 0x00ff;
  conv.b[3] = (hi >> 8) & 0x00ff;
#else
  conv.b[3] = lo & 0x00ff;
  conv.b[2] = (lo >> 8) & 0x00ff;
  conv.b[1] = hi & 0x00ff;
  conv.b[0] = (hi >> 8) & 0x00ff;
#endif

  return (conv.f);
} /* }}} float mb_register_to_float */

static int mb_read (mb_internal_t *dev, int register_addr, _Bool is_float) /* {{{ */
{
  int status;
  uint16_t values[2];
