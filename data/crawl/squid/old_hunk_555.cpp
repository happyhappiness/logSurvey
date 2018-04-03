                    sb.append(mb2.buf, mb2.size);
                    mb2.clean();
                }

                first = 0;
            }
            break;
        case Format::LFT_PERCENT:
            str = "%";
            break;

        default:
            // TODO: replace this function with Format::assemble()
            // For now die on unsupported logformat codes.
            fatalf("ERROR: unknown external_acl_type format %u", (uint8_t)format->type);
            break;
        }

        if (str)
            if (!*str)
                str = NULL;

        if (!str)
            str = "-";

        if (!first)
            mb.append(" ", 1);

        if (acl_data->def->quote == external_acl::QUOTE_METHOD_URL) {
            const char *quoted = rfc1738_escape(str);
            mb.append(quoted, strlen(quoted));
        } else {
            strwordquote(&mb, str);
        }

        sb.clean();

        first = 0;
    }

    if (!data_used) {
        for (arg = acl_data->arguments; arg; arg = arg->next) {
            if (!first)
                mb.append(" ", 1);

            if (acl_data->def->quote == external_acl::QUOTE_METHOD_URL) {
                const char *quoted = rfc1738_escape(arg->key);
                mb.append(quoted, strlen(quoted));
            } else {
                strwordquote(&mb, arg->key);
            }

            first = 0;
        }
    }

    return mb.buf;
}

