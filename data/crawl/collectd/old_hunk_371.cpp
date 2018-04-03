
static void http_send_buffer (char *buffer) /* {{{ */
{
        printf("Sending: --------\n");
        printf(buffer);
        printf("---------------\n");

        int status = 0;
        curl_easy_setopt (curl, CURLOPT_POSTFIELDS, buffer);
        status = curl_easy_perform (curl);
