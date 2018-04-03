int
getMyPort(void)
{
#if USE_SSL
    if (Config.Sockaddr.http)
	return ntohs(Config.Sockaddr.http->s.sin_port);
    else
	return ntohs(Config.Sockaddr.https->s.sin_port);
#else
    return ntohs(Config.Sockaddr.http->s.sin_port);
#endif
}