            cur++;
    }

    // For upward compatibility, assume "http::" prefix as default prefix
    // for all log access formating codes, except those starting
    // from "icap::", "adapt::" and "%"
    if (strncmp(cur,"http::", 6) == 0 &&
            strncmp(cur+6, "icap::", 6) != 0  &&
            strncmp(cur+6, "adapt::", 12) != 0 && *(cur+6) != '%' ) {
        cur += 6;
    }

    type = LFT_NONE;

    for (lte = TokenTable; lte->config != NULL; lte++) {
        if (strncmp(lte->config, cur, strlen(lte->config)) == 0) {
            type = lte->token_type;
            cur += strlen(lte->config);
            break;
        }
    }

    if (type == LFT_NONE) {
        fatalf("Can't parse configuration token: '%s'\n",
               def);
    }

    if (*cur == ' ') {
