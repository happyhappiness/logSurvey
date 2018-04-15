         metric_name, timestamp, value);
     send_buffer_fill += status;
 
-    printf(send_buffer);
-    printf("Fill: %i\n", send_buffer_fill);
-    printf("----\n");
-
     if ((sizeof (send_buffer) - send_buffer_fill) < 128)
     {
             http_flush_buffer();