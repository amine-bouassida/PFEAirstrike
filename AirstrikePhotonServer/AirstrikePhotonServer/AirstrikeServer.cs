using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Photon.SocketServer;
using System.Collections;

namespace AirstrikePhotonServer
{
    public class AirstrikeServer : ApplicationBase
    {
        private ArrayList servers;
        protected override PeerBase CreatePeer(InitRequest initRequest)
        {
            return new AirstrikePeer(initRequest.Protocol, initRequest.PhotonPeer, servers);
        }

        protected override void Setup()
        {
            this.servers = new ArrayList();
        }

        protected override void TearDown()
        {
        }
    }
}
