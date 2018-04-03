            fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);

        return true;
    }

    return false;
}
