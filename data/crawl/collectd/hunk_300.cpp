 
 /* ========= */
 
-#if 0
-static int foo (void) /* {{{ */
-{
-  int status;
-  uint16_t values[2];
-  int values_num;
-
-  if (dev == NULL)
-    return (EINVAL);
-
-  printf ("mb_read (addr = %i, float = %s);\n", register_addr,
-      is_float ? "true" : "false");
-
-  memset (values, 0, sizeof (values));
-  if (is_float)
-    values_num = 2;
-  else
-    values_num = 1;
-
-  status = read_holding_registers (dev->connection,
-      /* slave = */ 1, /* start_addr = */ register_addr,
-      /* num_registers = */ values_num, /* buffer = */ values);
-  printf ("read_coil_status returned with status %i\n", status);
-  if (status <= 0)
-    return (EAGAIN);
-
-  if (is_float)
-  {
-    float value = mb_register_to_float (values[0], values[1]);
-    printf ("read_coil_status returned value %g (hi %#"PRIx16", lo %#"PRIx16")\n",
-        value, values[0], values[1]);
-  }
-  else
-  {
-    printf ("read_coil_status returned value %"PRIu16"\n", values[0]);
-  }
-
-  return (0);
-} /* }}} int foo */
-#endif
-
 static int mb_shutdown (void) /* {{{ */
 {
   data_free_all (data_definitions);