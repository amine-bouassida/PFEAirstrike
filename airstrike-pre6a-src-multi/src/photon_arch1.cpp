#include "Photon-cpp/inc/PhotonPeer.h"
using namespace std;
using namespace ExitGames::Photon;
using namespace ExitGames::Common;

class PhotonLib : public PhotonListener
{
public:
	PhotonLib();
	~PhotonLib();
	void Run(const ExitGames::Common::JString& ipAddr);
	void onOperationResponse(const OperationResponse& operationResponse);
	void onStatusChanged(int statusCode);
	void onEvent(const EventData& eventData);
	void debugReturn(ExitGames::Common::DebugLevel::DebugLevel debugLevel, const ExitGames::Common::JString& string);
private:
	PhotonPeer * peer;
};

#include <iostream>
#include "photon_arch1.h"

PhotonLib::PhotonLib()
{
	peer = new PhotonPeer(*this);
}

PhotonLib::~PhotonLib()
{
	delete peer;
}
void PhotonLib::onOperationResponse(const OperationResponse& operationResponse)
{
	cout << operationResponse.toString() << endl;
}

void PhotonLib::onStatusChanged(int statusCode)
{

}

void PhotonLib::onEvent(const EventData& eventData)
{

}

void PhotonLib::debugReturn(DebugLevel::DebugLevel debugLevel, const JString& string)
{

}

void PhotonLib::Run(const JString& ipAddr)
{
	if (peer->connect(ipAddr))
	{
		cout << "Connected to " << ipAddr << endl;
		peer->service();
		OperationRequestParameters params;
		cout << "Sending data..." << endl;
		params.put((nByte)1, ValueObject<JString>(ipAddr));
		peer->opCustom(OperationRequest(9, params), true);
		peer->disconnect();
		cout << "Disconnected from " << ipAddr << "." << endl;
	}
	else
		cout << "Failed to connect to " << ipAddr << endl;
}

void NotifyPhotonServer()
{
	JString ipAddr(L"192.168.60.2:5055");
	PhotonLib * photonLib = new PhotonLib();
	photonLib->Run(ipAddr);
	delete photonLib;
}

// int main(int argc, char const *argv[])
// {
// 	NotifyPhotonServer();
// 	return 0;
// }
