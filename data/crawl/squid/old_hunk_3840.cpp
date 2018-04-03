// Called when we receive a 204 No Content response and
// when we are trying to bypass a service failure.
// We actually start sending (echoig or not) in startSending.
void ICAPModXact::prepEchoing()
{
    disableBypass("preparing to echo content");

