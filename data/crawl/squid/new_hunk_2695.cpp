
// received adapted response headers (body may follow)
void
ServerStateData::noteAdaptationAnswer(const Adaptation::Answer &answer)
{
    clearAdaptation(adaptedHeadSource); // we do not expect more messages

    switch (answer.kind) {
    case Adaptation::Answer::akForward:
        handleAdaptedHeader(answer.message);
        break;

    case Adaptation::Answer::akBlock:
        handleAdaptationBlocked(answer);
        break;

    case Adaptation::Answer::akError:
        handleAdaptationAborted(!answer.final);
        break;
    }
}

void
ServerStateData::handleAdaptedHeader(HttpMsg *msg)
{
    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
        return;

