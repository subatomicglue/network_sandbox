https://conan.io/center

# nanomsg nng
https://github.com/nanomsg/nng

# rest server
```
$ PORT=8888 && ./build/nng/rest_server_nng
$ curl -d ABC http://127.0.0.1:8888/api/rest/rot13; echo
NOP
$ curl -d NOP http://127.0.0.1:8888/api/rest/rot13; echo
ABC
```

# client/server
```
$ cd nng
$ ./run.sh
```
