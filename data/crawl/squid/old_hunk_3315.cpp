 * there is enough space in the payload string to accommodate the
 * added value.
 * payload_length and hdr will be modified as a side-effect.
 * base_offset is the payload offset from the packet's beginning, and is
 */
void
ntlm_add_to_payload(char *payload, int *payload_length,
                    strhdr * hdr, char *toadd,
                    int toadd_length, int base_offset)
{

    int l = (*payload_length);
    memcpy(payload + l, toadd, toadd_length);

    hdr->len = htole16(toadd_length);
    hdr->maxlen = htole16(toadd_length);
    hdr->offset = htole32(l + base_offset);	/* 48 is the base offset of the payload */
    (*payload_length) += toadd_length;
}


/**
 * Prepares a base64-encode challenge packet to be sent to the client
 * \note domain should be upper_case
 * \note the storage type for the returned value depends on
 *    base64_encode_bin. Currently this means static storage.
 */
const char *
ntlm_make_challenge(char *domain, char *domain_controller,
                    char *challenge_nonce, int challenge_nonce_len)
{
    ntlm_challenge ch;
    int pl = 0;
    const char *encoded;
    memset(&ch, 0, sizeof(ntlm_challenge));	/* reset */
    memcpy(ch.hdr.signature, "NTLMSSP", 8);		/* set the signature */
    ch.hdr.type = htole32(NTLM_CHALLENGE);	/* this is a challenge */
    ntlm_add_to_payload(ch.payload, &pl, &ch.target, domain, strlen(domain),
                        NTLM_CHALLENGE_HEADER_OFFSET);
    ch.flags = htole32(
                   REQUEST_NON_NT_SESSION_KEY |
                   CHALLENGE_TARGET_IS_DOMAIN |
                   NEGOTIATE_ALWAYS_SIGN |
                   NEGOTIATE_USE_NTLM |
                   NEGOTIATE_USE_LM |
                   NEGOTIATE_ASCII |
                   0
               );
    ch.context_low = 0;		/* check this out */
    ch.context_high = 0;
    memcpy(ch.challenge, challenge_nonce, challenge_nonce_len);
    encoded = base64_encode_bin((char *) &ch, NTLM_CHALLENGE_HEADER_OFFSET + pl);
    return encoded;
}