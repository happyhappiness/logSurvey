
    escape_string (metric_name, sizeof (metric_name));

    status = ssnprintf (csv_buffer + offset, sizeof (csv_buffer) - offset,
        "\"%s\",%s,%s\n",
        metric_name, timestamp, value);
    offset += status;

  } /* for */

  printf(csv_buffer);

  pthread_mutex_lock (&send_lock);

  curl_easy_setopt (curl, CURLOPT_POSTFIELDS, csv_buffer);
  status = curl_easy_perform (curl);
  if (status != 0)
  {
    ERROR ("curl plugin: curl_easy_perform failed with staus %i: %s",
        status, curl_errbuf);
    return (-1);
  }

  pthread_mutex_unlock (&send_lock);

  return (0);
