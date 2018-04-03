void ICAPServiceRep::invalidate()
{
    assert(self != NULL);
    self = NULL; // may destroy us and, hence, invalidate cbdata(this)
    // TODO: it would be nice to invalidate cbdata(this) when not destroyed
}

bool ICAPServiceRep::up() const
{
    return self != NULL && theState == stateUp;
}

bool ICAPServiceRep::wantsPreview(size_t &wantedSize) const
{
    Must(up());

    if (theOptions->preview < 0)
        return false;

    wantedSize = theOptions->preview;

    return true;
}

bool ICAPServiceRep::allows204() const
{
    Must(up());
    return true; // in the future, we may have ACLs to prevent 204s
}

