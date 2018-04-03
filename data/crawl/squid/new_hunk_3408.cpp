#ifdef EAI_NONAME
    case EAI_NONAME:
#endif
        printf("$fail DNS Domain/IP '%s' exists without any FQDN/IPs: %s.\n", buf, gai_strerror(res));
        break;
#endif
    default:
        printf("$fail A system error occured looking up Domain/IP '%s': %s.\n", buf, gai_strerror(res));
    }

    freeaddrinfo(AI);
}

/**
