        return;

    default:
        fatal("Hit unreachable code in Http::Stream::writeComplete\n");
    }
}

void
Http::Stream::pullData()
{
    debugs(33, 5, reply << " written " << http->out.size << " into " << clientConnection);

