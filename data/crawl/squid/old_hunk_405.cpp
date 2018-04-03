        return;

    default:
        fatal("Hit unreachable code in Http::StreamContext::writeComplete\n");
    }
}

void
Http::StreamContext::pullData()
{
    debugs(33, 5, reply << " written " << http->out.size << " into " << clientConnection);

