#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <enet/enet.h>
#include "network.h"

void *thread_function( void *arg );
void network_loop();

void network_init(){
	pthread_t thread;
	int rc;
	rc = pthread_create( &thread, NULL, thread_function, NULL);
	if(rc)
		error(EXIT_FAILURE, rc, "pthread_create");
}

void *thread_function( void *arg ){


	network_keymap[0][0]=1;
	network_keymap[0][1]=1;
	network_keymap[0][2]=1;
	network_keymap[0][3]=1;
	network_keymap[0][4]=1;
	network_loop();
	pthread_exit(NULL);
}

void network_loop(){

	int rc;
	rc = enet_initialize();
	if(rc)
		error(EXIT_FAILURE, rc, "An error occurred while initializing ENet.\n");

	ENetAddress address;
	ENetHost *server;

	/* Bind the server to the default localhost.     */
	/* A specific host address can be specified by   */
	/* enet_address_set_host (& address, "x.x.x.x"); */

	address.host = ENET_HOST_ANY;
	/* Bind the server to port 1234. */
	address.port = 1234;

	server = enet_host_create(&address /* the address to bind the server host to */ ,
			32 /* allow up to 32 clients and/or outgoing connections */ ,
			2 /* allow up to 2 channels to be used, 0 and 1 */ ,
			0 /* assume any amount of incoming bandwidth */ ,
			0 /* assume any amount of outgoing bandwidth */ );
	if (server == NULL) {
		fprintf(stderr, "An error occurred while trying to create an ENet server host.\n");
		exit(EXIT_FAILURE);
	}


	ENetEvent event;

	while (42) {
		int serviceResult = 1;

		/* Keep doing host_service until no events are left */
		while (serviceResult > 0) {
			/* Wait up to 1000 milliseconds for an event. */
			serviceResult = enet_host_service(server, &event, 1000);

			if (serviceResult > 0) {

				switch (event.type) {
				case ENET_EVENT_TYPE_CONNECT:
					printf("A new client connected from %x:%u.\n", event.peer->address.host, event.peer->address.port);

					/* Store any relevant client information here. */
					event.peer->data = (void *)"Client information";

					break;

				case ENET_EVENT_TYPE_RECEIVE:
					printf("A packet of length %u containing '%s' was received from %s on channel %u.\n",
							event.packet->dataLength, (char*)event.packet->data, (char*)event.peer->data, event.channelID);
					/* Tell all clients about this message */
					enet_host_broadcast(server, 0, event.packet);
					break;

				case ENET_EVENT_TYPE_DISCONNECT:
					printf("%s disconected.\n", (char*)event.peer->data);

					/* Reset the peer's client information. */

					event.peer->data = NULL;

					break;
				}
			} else if (serviceResult > 0) {
				puts("Error with servicing the server");
				exit(EXIT_FAILURE);
			}
		}
	}

}
