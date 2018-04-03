 */
bool

acl_ip_data::DecodeMask(const char *asc, struct in_addr *mask)
{
    char junk;
    int a1 = 0;

    if (!asc || !*asc)
    {
        mask->s_addr = htonl(0xFFFFFFFFul);
        return 1;
    }

    if (sscanf(asc, "%d%c", &a1, &junk) == 1 && a1 >= 0 && a1 < 33)
    {		/* a significant bits value for a mask */
        mask->s_addr = a1 ? htonl(0xfffffffful << (32 - a1)) : 0;
        return 1;
    }

    /* dotted notation */
    if (safe_inet_addr(asc, mask))
        return 1;

    debug(28, 0) ("DecodeAddress: Invalid IP address: '%s'\n", asc);

    return 0;
}

#define SCAN_ACL1       "%[0123456789.]-%[0123456789.]/%[0123456789.]"
#define SCAN_ACL2       "%[0123456789.]-%[0123456789.]%c"
#define SCAN_ACL3       "%[0123456789.]/%[0123456789.]"

acl_ip_data *
acl_ip_data::FactoryParse(const char *t)
