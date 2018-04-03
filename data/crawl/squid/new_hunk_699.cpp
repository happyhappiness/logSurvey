                    mb2.clean();
                }

                first = false;
            }
        }

        if (t->type == Format::LFT_USER_IDENT) {
            if (!ch->rfc931 || !*ch->rfc931) {
                // if we fail to go async, we still return NULL and the caller
                // will detect the failure in ACLExternal::match().
                (void)ch->goAsync(IdentLookup::Instance());
                return NULL;
            }
        }
    }

    acl_data->def->format.assemble(mb, ch->al, 0);

    return mb.buf;
}

