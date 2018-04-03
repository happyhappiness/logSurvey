
void Adaptation::Icap::Xaction::disableRetries()
{
    debugs(93,5, typeName << (isRetriable ? " becomes" : " remains") <<
           " final" << status());
    isRetriable = false;
}

void Adaptation::Icap::Xaction::start()
{
    Adaptation::Initiate::start();
