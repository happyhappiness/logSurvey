
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
 * kick off as needed.
 *
 * XXX: If an async call ends the ClientHttpRequest job, ClientSocketContext
 * (and ConnStateData) may not know about it, leading to segfaults and
 * assertions like areAllContextsForThisConnection(). This is difficult to fix
 * because ClientHttpRequest lacks a good way to communicate its ongoing
 * destruction back to the ClientSocketContext which pretends to "own" *http.
 */
