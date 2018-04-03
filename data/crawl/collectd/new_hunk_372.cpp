        metric_name, timestamp, value);
    send_buffer_fill += status;

    if ((sizeof (send_buffer) - send_buffer_fill) < 128)
    {
            http_flush_buffer();