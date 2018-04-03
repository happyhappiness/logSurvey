
  escape_string (metric_name, sizeof (metric_name));

  fprintf (stdout,
      "\"%s\",%s,%s\n",
      metric_name, timestamp, values);
  return (0);

} /* int http_write */

void module_register (void)
{
  plugin_register_config ("http", http_config,
      config_keys, config_keys_num);
  plugin_register_write ("http", http_write, /* user_data = */ NULL);