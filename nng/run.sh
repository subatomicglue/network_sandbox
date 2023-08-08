#!/usr/bin/env bash

#ADDR=ipc:///tmp/async_demo
#ADDR=tcp://127.0.0.1:5655
ADDR=udp://127.0.0.1:5655
COUNT=10

../build/nng/server_nng $ADDR &
SERVER_PID=$!
trap "kill $SERVER_PID" 0
typeset -a CLIENT_PID
i=0
sleep 1
while (( i < COUNT ))
do
	i=$(( i + 1 ))
	rnd=$(( RANDOM % 1000 + 500 ))
	echo "Starting client $i: server replies after $rnd msec"
	../build/nng/client_nng $ADDR $rnd &
	eval CLIENT_PID[$i]=$!
done

i=0
while (( i < COUNT ))
do
	i=$(( i + 1 ))
	wait ${CLIENT_PID[$i]}
done
kill $SERVER_PID
