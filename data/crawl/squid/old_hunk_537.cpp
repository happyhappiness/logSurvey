
/**
 * Badly named.
 * This is in fact the processing context for a single HTTP request.
 *
 * Managing what has been done, and what happens next to the data buffer
 * holding what we hope is an HTTP request.
 *
 * Parsing is still a mess of global functions done in conjunction with the
 * real socket controller which generated ClientHttpRequest.
 * It also generates one of us and passes us control from there based on
 * the results of the parse.
 *
 * After that all the request interpretation and adaptation is in our scope.
 * Then finally the reply fetcher is created by this and we get the result
 * back. Which we then have to manage writing of it to the ConnStateData.
 *
 * The socket level management is done by a ConnStateData which owns us.
 * The scope of this objects control over a socket consists of the data
 * buffer received from ConnStateData with an initially unknown length.
 * When that length is known it sets the end bounary of our acces to the
 * buffer.
 *
 * The individual processing actions are done by other Jobs which we
