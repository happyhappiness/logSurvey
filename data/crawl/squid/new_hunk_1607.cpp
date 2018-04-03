static void
usage(const char *progname)
{
    std::cerr << "Version: " << VERSION << std::endl
            << "Usage: " << progname << " [Basic Options] [HTTP Options]" << std::endl
            << std::endl
            << "Basic Options:" << std::endl
            << "    -g count     Ping mode, perform \"count\" iterations (0 to loop until interrupted)." << std::endl
            << "    -h host      Send message to server on 'host'.  Default is localhost." << std::endl
            << "    -I interval  Ping interval in seconds (default 1 second)." << std::endl
            << "    -l host      Specify a local IP address to bind to.  Default is none." << std::endl
            << "    -p port      Port number on server to contact. Default is " << CACHE_HTTP_PORT << "." << std::endl
            << "    -s           Silent.  Do not print response message to stdout." << std::endl
            << "    -T timeout   Timeout value (seconds) for read/write operations." << std::endl
            << "    -v           Verbose. Print outgoing request message and actions to stderr." << std::endl
            << std::endl
            << "HTTP Options:" << std::endl
            << "    -a           Do NOT include Accept: header." << std::endl
            << "    -A           User-Agent: header. Use \"\" to omit." << std::endl
            << "    -H 'string'  Extra headers to send. Use '\\n' for new lines." << std::endl
            << "    -i IMS       If-Modified-Since time (in Epoch seconds)." << std::endl
            << "    -j hosthdr   Host header content" << std::endl
            << "    -k           Keep the connection active. Default is to do only one request then close." << std::endl
            << "    -m method    Request method, default is GET." << std::endl
#if HAVE_GSSAPI
            << "    -n           Proxy Negotiate(Kerberos) authentication" << std::endl
            << "    -N           WWW Negotiate(Kerberos) authentication" << std::endl
#endif
            << "    -P file      PUT request. Using the named file" << std::endl
            << "    -r           Force cache to reload URL." << std::endl
            << "    -t count     Trace count cache-hops" << std::endl
            << "    -u user      Proxy authentication username" << std::endl
            << "    -U user      WWW authentication username" << std::endl
            << "    -V version   HTTP Version. Use '-' for HTTP/0.9 omitted case" << std::endl
            << "    -w password  Proxy authentication password" << std::endl
            << "    -W password  WWW authentication password" << std::endl
    ;
    exit(1);
}
