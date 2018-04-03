
    if ((int32_t)le32toh(hdr->type) != type) {
        /* don't report this error - it's ok as we do a if() around this function */
//      fprintf(stderr, "ntlmCheckHeader: type is %d, wanted %d\n", le32toh(hdr->type), type);
        return NTLM_ERR_PROTOCOL;
    }
    return NTLM_ERR_NONE;
