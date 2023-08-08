#include "zmq_addon.hpp"
#include "zmq.hpp"

// https://conan.io/center
//
// cppzmq
// https://github.com/zeromq/cppzmq
// https://brettviren.github.io/cppzmq-tour/index.html
// http://api.zeromq.org/master:zmq-socket

zmq::context_t ctx;
zmq::socket_t socket_client(ctx, zmq::socket_type::pull);
zmq::socket_t socket_server(ctx, zmq::socket_type::push);

int test1()
{
    zmq::context_t ctx;
    zmq::socket_t sock1(ctx, zmq::socket_type::push);
    zmq::socket_t sock2(ctx, zmq::socket_type::pull);
    sock1.bind("tcp://127.0.0.1:*");
    const std::string last_endpoint =
        sock1.get(zmq::sockopt::last_endpoint);
    printf( "Connecting to %s\n", last_endpoint.c_str() );
    sock2.connect(last_endpoint);

    std::array<zmq::const_buffer, 2> send_msgs = {
        zmq::str_buffer("foo"),
        zmq::str_buffer("bar!")
    };
    if (!zmq::send_multipart(sock1, send_msgs))
        return 1;

    std::vector<zmq::message_t> recv_msgs;
    const auto ret = zmq::recv_multipart( sock2, std::back_inserter( recv_msgs ) );
    if (!ret)
      return 1;
    printf( "Got %ld messages\n", *ret );
    return 0;
}

int main() {
  // Or, from string literal (see also str_buffer).
  //msg.rebuild(bytes, size);
  //const char* str = msg.data<char>();
  //std::string_view strv = msg.to_string_view();
  test1();
/*
  std::thread t( [=]() {
    zmq::message_t msg("hello world!", 12);
    //const std::string addr = "udp://127.0.0.1:5678";
    const std::string addr = "inproc://test";
    zmq::context_t ctx;
    socket_server.bind(addr);
    socket_server.connect(addr);
    socket_server.set(zmq::sockopt::immediate, false);
    auto res = socket_server.send(msg, zmq::send_flags::none);
    socket_server.unbind(addr);
    socket_server.disconnect(addr);
    printf( "thread2\n" );
  } );

  std::thread t2( [=]() {
    zmq::message_t msg("hello world!", 12);
    //const std::string addr = "udp://127.0.0.1:5678";
    const std::string addr = "inproc://test";
    zmq::context_t ctx;
    socket_client.bind(addr);
    socket_client.connect(addr);
    socket_client.set(zmq::sockopt::immediate, false);
    auto res = socket_client.recv(msg, zmq::recv_flags::none);
    printf( "thread2\n" );
  });

  printf( "hello world\n" );
  t2.join();
  t.join();
  */
  return 0;
}
