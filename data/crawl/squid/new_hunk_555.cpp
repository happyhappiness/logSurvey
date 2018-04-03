                    sb.append(mb2.buf, mb2.size);
                    mb2.clean();
                }
            }

            ch->al->lastAclData = xstrdup(sb.c_str());
        }

#if USE_IDENT
        if (t->type == Format::LFT_USER_IDENT) {
            if (!*ch->rfc931) {
                // if we fail to go async, we still return NULL and the caller
                // will detect the failure in ACLExternal::match().
                (void)ch->goAsync(IdentLookup::Instance());
                return NULL;
            }
        }
#endif
    }

    // assemble the full helper lookup string
    acl_data->def->format.assemble(mb, ch->al, 0);

    return mb.buf;
}

