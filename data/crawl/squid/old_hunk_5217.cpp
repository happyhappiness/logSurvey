}

ESIElement::Pointer
esiLiteral::makeUsable(esiTreeParentPtr , esiVarState &newVarState) const
{
    debug (86,5)("esiLiteral::makeUsable: Creating usable literal\n");
    esiLiteral * result = new esiLiteral (*this);
    result->varState = cbdataReference (&newVarState);
    return result;
}

/* esiInclude */
esiInclude::~esiInclude()
{
    debug (86,5)("esiInclude::Free %p\n", this);
    ESISegmentFreeList (srccontent);
    ESISegmentFreeList (altcontent);
    cbdataReferenceDone (varState);
    safe_free (srcurl);
    safe_free (alturl);
}

void
esiInclude::finish()
{
    parent = NULL;
}

void *
esiInclude::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiInclude));

    if (!Pool)
        Pool = memPoolCreate ("esiInclude", sizeof (esiInclude));

    return memPoolAlloc(Pool);
}

void
esiInclude::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
esiInclude::deleteSelf() const
{
    delete this;
}

ESIElement::Pointer
esiInclude::makeCacheable() const
{
    return new esiInclude (*this);
}

ESIElement::Pointer
esiInclude::makeUsable(esiTreeParentPtr newParent, esiVarState &newVarState) const
{
    esiInclude *resultI = new esiInclude (*this);
    ESIElement::Pointer result = resultI;
    resultI->parent = newParent;
    resultI->varState = cbdataReference (&newVarState);

    if (resultI->srcurl)
        resultI->src = esiStreamContextNew (resultI);

    if (resultI->alturl)
        resultI->alt = esiStreamContextNew (resultI);

    return result;
}

esiInclude::esiInclude(esiInclude const &old) : parent (NULL), started (false), sent (false)
{
    varState = NULL;
    flags.onerrorcontinue = old.flags.onerrorcontinue;

    if (old.srcurl)
        srcurl = xstrdup (old.srcurl);

    if (old.alturl)
        alturl = xstrdup (old.alturl);
}

void
esiInclude::Start (ESIStreamContext::Pointer stream, char const *url, esiVarState *vars)
{
    HttpHeader tempheaders;

    if (!stream.getRaw())
        return;

    httpHeaderInit (&tempheaders, hoRequest);

    /* Ensure variable state is clean */
    vars->feedData(url, strlen (url));

    /* tempUrl is eaten by the request */
    char const *tempUrl = vars->extractChar ();

    debug (86,5)("esiIncludeStart: Starting subrequest with url '%s'\n", tempUrl);

    if (clientBeginRequest(METHOD_GET, tempUrl, esiBufferRecipient, esiBufferDetach, stream.getRaw(), &tempheaders, stream->localbuffer->buf, HTTP_REQBUF_SZ)) {
        debug (86,0) ("starting new ESI subrequest failed\n");
    }

    httpHeaderClean (&tempheaders);
}

esiInclude::esiInclude (esiTreeParentPtr aParent, int attrcount, char const **attr, ESIContext *aContext) : parent (aParent), started (false), sent (false)
{
    int i;
    assert (aContext);

    for (i = 0; i < attrcount && attr[i]; i += 2) {
        if (!strcmp(attr[i],"src")) {
            /* Start a request for thisNode url */
            debug (86,5)("esiIncludeNew: Requesting source '%s'\n",attr[i+1]);
            /* TODO: don't assert on thisNode, ignore the duplicate */
            assert (src.getRaw() == NULL);
            src = esiStreamContextNew (this);
            assert (src.getRaw() != NULL);
            srcurl = xstrdup ( attr[i+1]);
        } else if (!strcmp(attr[i],"alt")) {
            /* Start a secondary request for thisNode url */
            /* TODO: make a config parameter to wait on requesting alt's
             * for the src to fail
             */
            debug (86,5)("esiIncludeNew: Requesting alternate '%s'\n",attr[i+1]);
            assert (alt.getRaw() == NULL); /* TODO: FIXME */
            alt = esiStreamContextNew (this);
            assert (alt.getRaw() != NULL);
            alturl = xstrdup (attr[i+1]);
        } else if (!strcmp(attr[i],"onerror")) {
            if (!strcmp(attr[i+1], "continue")) {
                flags.onerrorcontinue = 1;
            } else {
                /* ignore mistyped attributes */
                debug (86, 1)("invalid value for onerror='%s'\n", attr[i+1]);
            }
        } else {
            /* ignore mistyped attributes. TODO:? error on these for user feedback - config parameter needed
             */
        }
    }

    varState = cbdataReference(aContext->varState);
}

void
esiInclude::start()
{
    /* prevent freeing ourselves */
    esiIncludePtr foo(this);

    if (started)
        return;

    started = true;

    if (src.getRaw()) {
        Start (src, srcurl, varState);
        Start (alt, alturl, varState);
    } else {
        alt = NULL;

        debug (86,1)("esiIncludeNew: esi:include with no src attributes\n");

        flags.failed = 1;
    }
}

void
esiInclude::render(ESISegment::Pointer output)
{
    if (sent)
        return;

    ESISegment::Pointer myout;

    debug (86, 5)("esiIncludeRender: Rendering include %p\n", this);

    assert (flags.finished || (flags.failed && flags.onerrorcontinue));

    if (flags.failed && flags.onerrorcontinue) {
        return;
    }

    /* Render the content */
    if (srccontent.getRaw()) {
        myout = srccontent;
        srccontent = NULL;
    } else if (altcontent.getRaw()) {
        myout = altcontent;
        altcontent = NULL;
    } else
        fatal ("esiIncludeRender called with no content, and no failure!\n");

    assert (output->next == NULL);

    output->next = myout;

    sent = true;
}

esiProcessResult_t
esiInclude::process (int dovars)
{
    start();
    debug (86, 5)("esiIncludeRender: Processing include %p\n", this);

    if (flags.failed) {
        if (flags.onerrorcontinue)
            return ESI_PROCESS_COMPLETE;
        else
            return ESI_PROCESS_FAILED;
    }

    if (!flags.finished) {
        if (flags.onerrorcontinue)
            return ESI_PROCESS_PENDING_WONTFAIL;
        else
            return ESI_PROCESS_PENDING_MAYFAIL;
    }

    return ESI_PROCESS_COMPLETE;
}

void
esiInclude::fail (ESIStreamContext::Pointer stream)
{
    subRequestDone (stream, false);
}

bool
esiInclude::dataNeeded() const
{
    return !(flags.finished || flags.failed);
}

void
esiInclude::subRequestDone (ESIStreamContext::Pointer stream, bool success)
{
    assert (this);

    if (!dataNeeded())
        return;

    if (stream == src) {
        debug (86,3)("esiInclude::subRequestDone: %s\n", srcurl);

        if (success) {
            /* copy the lead segment */
            debug (86,3)("esiIncludeSubRequestDone: Src OK - include PASSED.\n");
            assert (!srccontent.getRaw());
            ESISegment::ListTransfer (stream->localbuffer, srccontent);
            /* we're done! */
            flags.finished = 1;
        } else {
            /* Fail if there is no alt being retrieved */
            debug (86,3)("esiIncludeSubRequestDone: Src FAILED\n");

            if (!(alt.getRaw() || altcontent.getRaw())) {
                debug (86,3)("esiIncludeSubRequestDone: Include FAILED - No ALT\n");
                flags.failed = 1;
            } else if (altcontent.getRaw()) {
                debug (86,3)("esiIncludeSubRequestDone: Include PASSED - ALT already Complete\n");
                /* ALT was already retrieved, we are done */
                flags.finished = 1;
            }
        }

        src = NULL;
    } else if (stream == alt) {
        debug (86,3)("esiInclude::subRequestDone: %s\n", alturl);

        if (success) {
            debug (86,3)("esiIncludeSubRequestDone: ALT OK.\n");
            /* copy the lead segment */
            assert (!altcontent.getRaw());
            ESISegment::ListTransfer (stream->localbuffer, altcontent);
            /* we're done! */

            if (!(src.getRaw() || srccontent.getRaw())) {
                /* src already failed, kick ESI processor */
                debug (86,3)("esiIncludeSubRequestDone: Include PASSED - SRC already failed.\n");
                flags.finished = 1;
            }
        } else {
            if (!(src.getRaw() || srccontent.getRaw())) {
                debug (86,3)("esiIncludeSubRequestDone: ALT FAILED, Include FAILED - SRC already failed\n");
                /* src already failed */
                flags.failed = 1;
            }
        }

        alt = NULL;
    } else {
        fatal ("esiIncludeSubRequestDone: non-owned stream found!\n");
    }

    if (flags.finished || flags.failed) {
        /* Kick ESI Processor */
        debug (86,5)("esiInclude %p SubRequest %p completed, kicking processor , status %s\n", this, stream.getRaw(), flags.finished ? "OK" : "FAILED");
        assert (parent.getRaw());

        if (!flags.failed) {
            sent = true;
            parent->provideData (srccontent.getRaw() ? srccontent:altcontent,this);

            if (srccontent.getRaw())
                srccontent = NULL;
            else
                altcontent = NULL;
        } else if (flags.onerrorcontinue) {
            /* render nothing but inform of completion */

            if (!sent) {
                sent = true;
                parent->provideData (new ESISegment, this);
            } else
                assert (0);
        } else
            parent->fail(this);
    }
}

/* esiRemove */
void
esiRemoveFree (void *data)
{
    esiRemove *thisNode = (esiRemove *)data;
    debug (86,5)("esiRemoveFree %p\n", thisNode);
}

void *
esiRemove::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiRemove));
    void *rv;
    CBDATA_INIT_TYPE_FREECB(esiRemove, esiRemoveFree);
    rv = (void *)cbdataAlloc (esiRemove);
    return rv;
}

void
esiRemove::operator delete (void *address)
{
    cbdataFree (address);
}

void
esiRemove::deleteSelf() const
{
    delete this;
}

ESIElement *
esiRemoveNew ()
{
    return new esiRemove;
}

esiRemove::esiRemove()
{}

void
esiRemove::finish()
{}

void
esiRemove::render(ESISegment::Pointer output)
{
    /* Removes do nothing dude */
    debug (86, 5)("esiRemoveRender: Rendering remove %p\n", this);
}

/* Accept non-ESI children */
bool
esiRemove::addElement (ESIElement::Pointer element)
{
    if (!dynamic_cast<esiLiteral*>(element.getRaw())) {
        debug (86,5)("esiRemoveAdd: Failed for %p\n",this);
        return false;
    }

    return true;
}

ESIElement::Pointer
esiRemove::makeCacheable() const
{
    debug (86,5)("esiRemove::makeCacheable: Returning NULL\n");
    return NULL;
}

ESIElement::Pointer
esiRemove::makeUsable(esiTreeParentPtr, esiVarState &) const
{
    fatal ("esiRemove::Usable: unreachable code!\n");
    return NULL;
}

/* esiTry */
esiTry::~esiTry()
{
    debug (86,5)("esiTry::~esiTry %p\n", this);
}

void *
esiTry::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiTry));

    if (!Pool)
        Pool = memPoolCreate ("esiTry", sizeof(esiTry));

    return memPoolAlloc (Pool);
}

void
esiTry::operator delete (void *address)
{
    memPoolFree (Pool, address);
}
