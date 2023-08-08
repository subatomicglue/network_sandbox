
#include "nng/nng.h"
#include "nng/compat/nanomsg/pair.h"
#include "nng/compat/nanomsg/inproc.h"
#include "nng/compat/nanomsg/reqrep.h"
#include "nng/compat/nanomsg/bus.h"
#include "nng/compat/nanomsg/pipeline.h"
#include "nng/compat/nanomsg/nn.h"
#include "nng/compat/nanomsg/survey.h"
#include "nng/compat/nanomsg/pubsub.h"
#include "nng/compat/nanomsg/ws.h"
#include "nng/compat/nanomsg/ipc.h"
#include "nng/compat/nanomsg/tcp.h"
#include "nng/protocol/pubsub0/sub.h"
#include "nng/protocol/pubsub0/pub.h"
#include "nng/protocol/pipeline0/pull.h"
#include "nng/protocol/pipeline0/push.h"
#include "nng/protocol/pair1/pair.h"
#include "nng/protocol/survey0/respond.h"
#include "nng/protocol/survey0/survey.h"
#include "nng/protocol/reqrep0/req.h"
#include "nng/protocol/reqrep0/rep.h"
#include "nng/protocol/bus0/bus.h"
#include "nng/protocol/pair0/pair.h"
#include "nng/supplemental/tls/engine.h"
#include "nng/supplemental/tls/tls.h"
#include "nng/supplemental/util/platform.h"
#include "nng/supplemental/util/options.h"
#include "nng/supplemental/http/http.h"
#include "nng/transport/tls/tls.h"
#include "nng/transport/zerotier/zerotier.h"
#include "nng/transport/ws/websocket.h"
#include "nng/transport/tcp/tcp.h"
#include "nng/transport/ipc/ipc.h"
#include "nng/transport/inproc/inproc.h"


// https://conan.io/center
//
// nanomsg nng
// https://github.com/nanomsg/nng


#include <stdio.h>

int main() {
  printf( "hello world\n" );
  return 0;
}
