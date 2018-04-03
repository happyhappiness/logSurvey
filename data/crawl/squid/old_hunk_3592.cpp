    return token;
}

int main(int argc, char *argv[])
{

    const char *Token;

    if (argc < 1) {
        fprintf(stderr, "%s| %s: Error: No proxy server name given\n", LogTime(), PROGRAM);
        exit(99);
    }
    Token = (const char *)squid_kerb_proxy_auth(argv[1]);
    fprintf(stdout,"Token: %s\n",Token?Token:"NULL");

    exit(0);
}

