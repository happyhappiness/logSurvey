    }
}

void Adaptation::Icap::ModXact::addLastRequestChunk(MemBuf &buf)
{
    const bool ieof = state.writing == State::writingPreview && preview.ieof();
    openChunk(buf, 0, ieof);
    closeChunk(buf);
}

void Adaptation::Icap::ModXact::openChunk(MemBuf &buf, size_t chunkSize, bool ieof)
{
    buf.Printf((ieof ? "%x; ieof\r\n" : "%x\r\n"), (int) chunkSize);
}

void Adaptation::Icap::ModXact::closeChunk(MemBuf &buf)
{
    buf.append(ICAP::crlf, 2); // chunk-terminating CRLF
}

// did the activity reached the end of the virgin body?
bool Adaptation::Icap::ModXact::virginBodyEndReached(const Adaptation::Icap::VirginBodyAct &act) const
{
    return
        !act.active() || // did all (assuming it was originally planned)
