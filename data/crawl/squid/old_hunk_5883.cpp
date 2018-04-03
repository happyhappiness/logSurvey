dnsSubmit(const char *lookup, HLPCB * callback, void *data)
{
    char buf[256];
    snprintf(buf, 256, "%s\n", lookup);
    helperSubmit(dnsservers, buf, callback, data);
}
