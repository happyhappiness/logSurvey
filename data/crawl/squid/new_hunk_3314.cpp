            (flags & REQUEST_NON_NT_SESSION_KEY ? "Req_nonnt_sesskey " : "")
           );
}

/* ************************************************************************* */
/* Packet and Payload handling functions */
/* ************************************************************************* */

/**
 * Check the validity of a decoded NTLM packet. Return -1 on error.
 */
int
ntlm_validate_packet(const ntlmhdr * hdr, const int type)
{
    /*
     * Must be the correct security package and request type.
     * The 8 bytes compared includes the ASCII 'NUL'.
     */
    if (memcmp(hdr->signature, "NTLMSSP", 8) != 0) {
        fprintf(stderr, "ntlmCheckHeader: bad header signature\n");
        return (-1);
    }
    if (type == NTLM_ANY)
        return 0;

    if (le32toh(hdr->type) != type) {
        /* don't report this error - it's ok as we do a if() around this function */
//      fprintf(stderr, "ntlmCheckHeader: type is %d, wanted %d\n", le32toh(hdr->type), type);
        return (-1);
    }
    return (0);
}

#define lstring_zero(s) s.str=NULL; s.l=-1;

/**
 * Fetches a string from the authentication packet.
 * The lstring data-part may point to inside the packet itself or a temporary static buffer.
 * It's up to the user to memcpy() that if the value needs to
 * be used in any way that requires a tailing \0. (can check whether the
 * value is there though, in that case lstring.length == -1).
 *
 * String may be either ASCII or UNICODE depending on whether flags contains NEGOTIATE_ASCII
 */
lstring
ntlm_fetch_string(const ntlmhdr *packet, const int32_t packet_size, const strhdr * str, const u_int32_t flags)
{
    int16_t l;			/* length */
    int32_t o;			/* offset */
    static char buf[NTLM_MAX_FIELD_LENGTH];
    lstring rv;
    u_short *s, c;
    char *d, *sc;

    lstring_zero(rv);

    l = le16toh(str->len);
    o = le32toh(str->offset);
    /* debug("fetch_string(plength=%d,l=%d,o=%d)\n",packet_size,l,o); */

    if (l < 0 || l > NTLM_MAX_FIELD_LENGTH || o + l > packet_size || o == 0) {
        /* debug("ntlmssp: insane data (l: %d, o: %d)\n", l,o); */
        return rv;
    }
    rv.str = (char *)packet + o;
    if ((flags & NEGOTIATE_ASCII) == 0) {
        /* UNICODE string */
        s = (u_short *) ((char *) packet + o);
        rv.str = d = buf;

        for (l >>= 1; l; s++, l--) {
            c = le16toh(*s);
            if (c > 254 || c == '\0') {
                fprintf(stderr, "ntlmssp: bad unicode: %04x\n", c);
                return rv;
            }
            *d++ = c;
            rv.l++;
        }
    } else {
        /* ASCII/OEM string */
        sc = (char *) packet + o;

        for (; l; l--) {
            if (*sc == '\0' || !xisprint(*sc)) {
                fprintf(stderr, "ntlmssp: bad ascii: %04x\n", *sc);
                return rv;
            }
            rv.l++;
        }
    }

    return rv;
}
