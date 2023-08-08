# nanomsg nng demos
links:
- https://conan.io/center (search for nng)
- https://github.com/nanomsg/nng
- https://nanomsg.org/gettingstarted/nng/pubsub.html
- https://github.com/cwzx/nngpp/tree/master/demo

# rest server
REST API Gateway demo
```
$ PORT=8888 && ./build/nng/rest_server_nng
$ curl -d ABC http://127.0.0.1:8888/api/rest/rot13; echo
NOP
$ curl -d NOP http://127.0.0.1:8888/api/rest/rot13; echo
ABC
```

# client/server
This is a simple asynchronous demo, that demonstrates use of the contexts and asynchronous message handling and operations, to obtain highly concurrent processing with minimal fuss.
```
$ cd nng
$ ./run.sh
```

# raw
This is a simple asynchronous demo, that demonstrates use of the RAW sockets with a server, along with async message handling, to obtain a very high level of asynchronous operation, suitable for use in a highly concurrent server application.
```
$ ./build/nng/raw_nng tcp://127.0.0.1:5555 -s
$ ./build/nng/raw_nng tcp://127.0.0.1:5555 2
Request took 2006 milliseconds.
```
