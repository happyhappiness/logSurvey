        break;

    case EAI_FAIL:
        printf("$fail DNS Domain/IP '%s' does not exist: %s.\n", buf, gai_strerror(res));
        break;

#if defined(EAI_NODATA) || defined(EAI_NONAME)
