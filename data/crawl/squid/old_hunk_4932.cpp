        node = (clientStreamNode *)http->client_stream.tail->data;
        clientStreamRead(node, http, node->readBuffer);
    }
}

static void
clientRedirectAccessCheckDone(int answer, void *data)
{
