        for (format = node->format; format; format = format->next) {
            switch (format->type) {

            case _external_acl_format::EXT_ACL_HEADER_REQUEST:
            case _external_acl_format::EXT_ACL_HEADER_REQUEST_ID:
                storeAppendPrintf(sentry, " %%>{%s}", format->header);
                break;

            case _external_acl_format::EXT_ACL_HEADER_REQUEST_MEMBER:
            case _external_acl_format::EXT_ACL_HEADER_REQUEST_ID_MEMBER:
                storeAppendPrintf(sentry, " %%>{%s:%s}", format->header, format->member);
                break;

            case _external_acl_format::EXT_ACL_HEADER_REPLY:
            case _external_acl_format::EXT_ACL_HEADER_REPLY_ID:
                storeAppendPrintf(sentry, " %%<{%s}", format->header);
                break;

            case _external_acl_format::EXT_ACL_HEADER_REPLY_MEMBER:
            case _external_acl_format::EXT_ACL_HEADER_REPLY_ID_MEMBER:
                storeAppendPrintf(sentry, " %%<{%s:%s}", format->header, format->member);
                break;
#define DUMP_EXT_ACL_TYPE(a) \
            case _external_acl_format::EXT_ACL_##a: \
                storeAppendPrintf(sentry, " %%%s", #a); \
                break
#define DUMP_EXT_ACL_TYPE_FMT(a, fmt, ...) \
            case _external_acl_format::EXT_ACL_##a: \
                storeAppendPrintf(sentry, fmt, ##__VA_ARGS__); \
                break
#if USE_AUTH
                DUMP_EXT_ACL_TYPE(LOGIN);
#endif
#if USE_IDENT

                DUMP_EXT_ACL_TYPE(IDENT);
#endif

                DUMP_EXT_ACL_TYPE(SRC);
                DUMP_EXT_ACL_TYPE(SRCPORT);
#if USE_SQUID_EUI
                DUMP_EXT_ACL_TYPE(SRCEUI48);
                DUMP_EXT_ACL_TYPE(SRCEUI64);
#endif

                DUMP_EXT_ACL_TYPE(MYADDR);
                DUMP_EXT_ACL_TYPE(MYPORT);
                DUMP_EXT_ACL_TYPE(URI);
                DUMP_EXT_ACL_TYPE(DST);
                DUMP_EXT_ACL_TYPE(PROTO);
                DUMP_EXT_ACL_TYPE(PORT);
                DUMP_EXT_ACL_TYPE(PATH);
                DUMP_EXT_ACL_TYPE(METHOD);
#if USE_OPENSSL
                DUMP_EXT_ACL_TYPE_FMT(USER_CERT_RAW, " %%USER_CERT_RAW");
                DUMP_EXT_ACL_TYPE_FMT(USER_CERTCHAIN_RAW, " %%USER_CERTCHAIN_RAW");
                DUMP_EXT_ACL_TYPE_FMT(USER_CERT, " %%USER_CERT_%s", format->header);
                DUMP_EXT_ACL_TYPE_FMT(USER_CA_CERT, " %%USER_CA_CERT_%s", format->header);
#endif
#if USE_AUTH
                DUMP_EXT_ACL_TYPE(EXT_USER);
#endif
                DUMP_EXT_ACL_TYPE(EXT_LOG);
                DUMP_EXT_ACL_TYPE(TAG);
                DUMP_EXT_ACL_TYPE_FMT(PERCENT, " %%%%");
            default:
                fatal("unknown external_acl format error");
