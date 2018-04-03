static void
auth_html(const char *host, int port, const char *user_name)
{
    if (!user_name)
        user_name = "";

    if (!host || !strlen(host))
        host = "localhost";

    printf("Content-Type: text/html\r\n\r\n");

