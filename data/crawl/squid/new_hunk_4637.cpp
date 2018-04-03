    if (commBuf)
        memFreeBuf(commBufSize, commBuf);

    if (theInitiator)
        tellQueryAborted(!isRetriable);

    ICAPInitiate::swanSong();
}

// returns a temporary string depicting transaction status, for debugging
