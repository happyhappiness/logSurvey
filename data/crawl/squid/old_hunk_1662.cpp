    mustStop("adaptationAborted");
}

bool
Adaptation::Ecap::XactionRep::callable() const
{
    return !done();
}

void
Adaptation::Ecap::XactionRep::noteMoreBodySpaceAvailable(RefCount<BodyPipe> bp)
{
