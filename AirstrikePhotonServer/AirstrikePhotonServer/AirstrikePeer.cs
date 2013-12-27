using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Photon.SocketServer;
using PhotonHostRuntimeInterfaces;
using System.Collections;

namespace AirstrikePhotonServer
{
    class AirstrikePeer : PeerBase
    {
        private ArrayList servers;
        private Dictionary<String, String> data;

        public AirstrikePeer(IRpcProtocol protocol, IPhotonPeer unmanagedPeer, ArrayList servers)
            : base(protocol, unmanagedPeer)
        {
            this.servers = servers;
        }

        protected override void OnDisconnect(DisconnectReason reasonCode, string reasonDetail)
        {
            servers.Remove(data);
        }

        protected override void OnOperationRequest(OperationRequest operationRequest, SendParameters sendParameters)
        {
            Dictionary<byte, object> parameters;
            OperationResponse response;
            switch (operationRequest.OperationCode)
            {
                // receiving data from an airstrike server
                case 1:
                    data = (Dictionary<String, String>)operationRequest.Parameters[1];
                    servers.Add(data);
                    parameters = new Dictionary<byte, object> { { 1, "Successfully added." }, { 2, servers } };
                    response = new OperationResponse(operationRequest.OperationCode, parameters);
                    this.SendOperationResponse(response, sendParameters);
                    break;
                // request to list all available airstrike servers' data
                case 2:
                    parameters = new Dictionary<byte, object> { { 1, "Available airstrike servers list." }, { 2, servers } };
                    response = new OperationResponse(operationRequest.OperationCode, parameters);
                    this.SendOperationResponse(response, sendParameters);
                    break;
            }
        }
    }
}
