    user_data_t __attribute__((unused)) *user_data)
{
  char         metric_name[512];
  char         values[512];
  char         timestamp[512];

  char csv_buffer[1536];

  int status;

  if (0 != strcmp (ds->type, vl->type)) {
    ERROR ("http plugin: DS type does not match value list type");
    return -1;
  }

  if (value_list_to_metric_name (metric_name, sizeof (metric_name), ds, vl) != 0)
    return (-1);

  DEBUG ("http plugin: http_write: metric_name = %s;", metric_name);

  if (value_list_to_timestamp (timestamp, sizeof (timestamp), ds, vl) != 0)
    return (-1);

  if (value_list_to_string (values, sizeof (values), ds, vl) != 0)
    return (-1);

  escape_string (metric_name, sizeof (metric_name));

  status = ssnprintf (csv_buffer, 1536,
      "\"%s\",%s,%s\n",
      metric_name, timestamp, values);

  curl_easy_setopt (curl, CURLOPT_POSTFIELDS, csv_buffer);
  status = curl_easy_perform (curl);