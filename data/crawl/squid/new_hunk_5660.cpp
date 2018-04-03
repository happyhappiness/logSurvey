int
getMyPort(void)
{
    if (Config.Sockaddr.http)
	return ntohs(Config.Sockaddr.http->s.sin_port);
#if USE_SSL
    if (Config.Sockaddr.https)
	return ntohs(Config.Sockaddr.https->s.sin_port);
#endif
    fatal("No port defined");
    return 0; /* NOT REACHED */
}