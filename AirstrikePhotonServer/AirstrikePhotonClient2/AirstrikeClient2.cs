using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ExitGames.Client.Photon;
using System.Collections;

namespace AirstrikePhotonClient
{
    class AirstrikeClient2 : IPhotonPeerListener
    {
        private bool connected;
        private bool responded;

        static void Main(string[] args)
        {
            var client = new AirstrikeClient2();
            var peer = new PhotonPeer(client, ConnectionProtocol.Tcp);

            Console.Write("Server IP [127.0.0.1]: ");
            String ip = Console.ReadLine();
            if (ip.Equals(""))
                ip = "127.0.0.1";
            // connect
            client.connected = false;
            peer.Connect(ip + ":4530", "AirstrikePhotonServer");
            while (!client.connected)
            {
                peer.Service();
            }
            Console.WriteLine("Connected to " + ip);
            var parameters = new Dictionary<byte, object> { };
            peer.OpCustom(2, null, true);
            client.responded = false;
            while (!client.responded)
            {
                System.Threading.Thread.Sleep(100);
                peer.Service();
            }
        }

        public void DebugReturn(DebugLevel level, string message)
        {
            Console.WriteLine(level + ": " + message);
        }

        public void OnEvent(EventData eventData)
        {
        }

        public void OnOperationResponse(OperationResponse operationResponse)
        {
            if (operationResponse.OperationCode == 2)
            {
                ArrayList servers = (ArrayList)operationResponse.Parameters[2];
                foreach (Dictionary<String, String> data in servers)
                {
                    foreach (KeyValuePair<String, String> pair in data)
                    {
                        Console.Write("[{0}={1}] ", pair.Key, pair.Value);
                    }
                    Console.WriteLine();
                }
                this.responded = true;
            }
            else
            {
                Console.WriteLine("Response: " + operationResponse.OperationCode);
            }
        }

        public void OnStatusChanged(StatusCode statusCode)
        {
            if (statusCode == StatusCode.Connect)
            {
                this.connected = true;
            }
            else
            {
                Console.WriteLine("Status: " + statusCode);
            }
        }
    }
}
