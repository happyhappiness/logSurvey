    Security::SessionPointer tmp;
    if (prepareSocket() && initializeTls(tmp))
        negotiateSsl();
    else
        mustStop("Security::PeerConnector TLS socket initialize failed");
}

void