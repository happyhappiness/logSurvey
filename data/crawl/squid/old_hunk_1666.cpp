
    if (!valid) {
        /* The pinning info is not safe, remove any pinning info */
        unpinConnection();
    }

    return pinning.serverConnection;
}

void
ConnStateData::unpinConnection()
{
    debugs(33, 3, HERE << pinning.serverConnection);

