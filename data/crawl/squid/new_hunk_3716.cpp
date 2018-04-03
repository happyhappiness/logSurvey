
void Adaptation::Icap::ModXact::bypassFailure()
{
    disableBypass("already started to bypass", false);

    Must(!isRetriable); // or we should not be bypassing
    // TODO: should the same be enforced for isRepeatable? Check icap_repeat??
