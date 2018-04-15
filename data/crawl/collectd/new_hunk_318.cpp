
  escape_string (metric_name, sizeof (metric_name));

  status = ssnprintf (csv_buffer, 1536,
      "\"%s\",%s,%s\n",
      metric_name, timestamp, values);

  curl_easy_setopt (curl, CURLOPT_POSTFIELDS, csv_buffer);
  status = curl_easy_perform (curl);
  if (status != 0)
  {
    ERROR ("curl plugin: curl_easy_perform failed with staus %i: %s",
        status, curl_errbuf);
    return (-1);
  }

  return (0);

} /* int http_write */

void module_register (void)
{
  plugin_register_init("http", http_init);
  plugin_register_config ("http", http_config,
      config_keys, config_keys_num);
  plugin_register_write ("http", http_write, /* user_data = */ NULL);