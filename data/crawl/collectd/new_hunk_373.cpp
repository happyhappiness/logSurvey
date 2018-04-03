  return (0);
} /* }}} int http_config */

static void http_init_buffer (void)  /* {{{ */
{
        memset (send_buffer, 0, sizeof (send_buffer));
        send_buffer_ptr = send_buffer;
        send_buffer_fill = 0;
} /* }}} http_init_buffer */

static void http_send_buffer (char *buffer) /* {{{ */
{
        printf("Sending: --------\n");
        printf(buffer);
        printf("---------------\n");

        int status = 0;
        curl_easy_setopt (curl, CURLOPT_POSTFIELDS, buffer);
        status = curl_easy_perform (curl);
        if (status != 0)
        {
                ERROR ("http plugin: curl_easy_perform failed with staus %i: %s",
                                status, curl_errbuf);
        }
} /* }}} http_send_buffer */

static void http_flush_buffer (void) /* {{{ */
{
	DEBUG ("http plugin: flush_buffer: send_buffer_fill = %i",
			send_buffer_fill);

	http_send_buffer (send_buffer);
	http_init_buffer ();
} /* }}} http_flush_buffer */

static int http_write (const data_set_t *ds, const value_list_t *vl, /* {{{ */
    user_data_t __attribute__((unused)) *user_data)
{
