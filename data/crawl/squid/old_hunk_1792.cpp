}

/// called when kid terminates, sets exiting status
void Kid::stop(status_type exitStatus)
{
    assert(running());
    assert(startTime != 0);
