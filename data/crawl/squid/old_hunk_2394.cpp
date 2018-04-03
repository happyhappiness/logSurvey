    }
}

// more adapted response body is available
void
ServerStateData::handleMoreAdaptedBodyAvailable()
{
    const size_t contentSize = adaptedBodySource->buf().contentSize();

    debugs(11,5, HERE << "consuming " << contentSize << " bytes of adapted " <<
           "response body at offset " << adaptedBodySource->consumedSize());

    if (abortOnBadEntry("entry refuses adapted body"))
        return;

    assert(entry);
    BodyPipeCheckout bpc(*adaptedBodySource);
    const StoreIOBuffer ioBuf(&bpc.buf, currentOffset);
    currentOffset += bpc.buf.size;
    entry->write(ioBuf);
    bpc.buf.consume(contentSize);
    bpc.checkIn();
