void
HttpRequest::clean()
{
    // we used to assert that the pipe is NULL, but now the request only 
    // points to a pipe that is owned and initiated by another object.
    body_pipe = NULL; 

    if (auth_user_request) {
        auth_user_request->unlock();
