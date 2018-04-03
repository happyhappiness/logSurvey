
    escape_string (metric_name, sizeof (metric_name));

    pthread_mutex_lock (&send_lock);

    status = ssnprintf (send_buffer + send_buffer_fill, sizeof (send_buffer) - send_buffer_fill,
        "\"%s\",%s,%s\n",
        metric_name, timestamp, value);
    send_buffer_fill += status;

    printf(send_buffer);
    printf("Fill: %i\n", send_buffer_fill);
    printf("----\n");

    if ((sizeof (send_buffer) - send_buffer_fill) < 128)
    {
            http_flush_buffer();
    }

    pthread_mutex_unlock (&send_lock);

  } /* for */


  return (0);
