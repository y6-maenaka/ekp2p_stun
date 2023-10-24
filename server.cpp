#include "server.h"

#include "./ekp2p/ekp2p.h"
#include "./ekp2p/network/nat/request_handler.h"

#include "./shared_components/stream_buffer/stream_buffer.h"
#include "./shared_components/stream_buffer/stream_buffer_container.h"

int main()
{
    std::mutex mtx;
    std::condition_variable cv;



    std::cout << "Hello World" << "\n";


		ekp2p::EKP2P ekp2p;
    ekp2p.initCustom();


		std::shared_ptr<StreamBufferContainer> toStunResponseHandlerDaemonSBC = std::make_shared<StreamBufferContainer>(); 
		ekp2p.assignBrokerDestination( toStunResponseHandlerDaemonSBC , ekp2p::DEFAULT_DAEMON_FORWARDING_SBC_ID_NATER );

		ekp2p::StunRequestHandlerDaemon stunRequestHandlerDaemon( toStunResponseHandlerDaemonSBC , ekp2p.toBrokerSBC() );

		stunRequestHandlerDaemon.start();
		int flag = ekp2p.start( false );
		std::cout << "flag :: " << flag << "\n";

    
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait( lock ) ;
}
