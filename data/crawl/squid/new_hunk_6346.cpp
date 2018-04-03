ssize_t
htcpBuildTstOpData(char *buf, size_t buflen, htcpStuff * stuff)
{
    switch(stuff->rr) {
    case RR_REQUEST:
        return htcpBuildSpecifier(buf, buflen, stuff);
    case RR_RESPONSE:
        return htcpBuildDetail(buf, buflen, stuff);
    default:
	fatal_dump("htcpBuildTstOpData: bad RR value");
   }
   return 0;
}

ssize_t
