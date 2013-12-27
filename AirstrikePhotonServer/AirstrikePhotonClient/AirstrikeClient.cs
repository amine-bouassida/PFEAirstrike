using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ExitGames.Client.Photon;
using System.Collections;

namespace AirstrikePhotonClient
{
    class AirstrikeClient : IPhotonPeerListener
    {
        private bool connected;

        static void Main(string[] args)
        {
            var client = new AirstrikeClient();
            var peer = new PhotonPeer(client, ConnectionProtocol.Tcp);

            Console.Write("Photon server IP [127.0.0.1]: ");
            String ip = Console.ReadLine();
            if (ip.Equals(""))
                ip = "127.0.0.1";
            Console.Write("Airstrike server IP : ");
            String myIp = Console.ReadLine();
            Console.Write("Port [1234]: ");
            String port = Console.ReadLine();
            if (port.Equals(""))
                port = "1234";
            Console.Write("Server name  : ");
            String name = Console.ReadLine();
            Dictionary<String, String> data = new Dictionary<String, String> { { "ip", myIp }, { "port", port }, { "name", name } };
            // connect
            client.connected = false;
            peer.Connect(ip + ":4530", "AirstrikePhotonServer");
            while (!client.connected)
            {
                peer.Service();
            }
            Console.WriteLine("\nConnected to {0}", ip);
            Console.WriteLine("Sending data...\n");
            var parameters = new Dictionary<byte, object> { { 1, data } };
            peer.OpCustom(1, parameters, true);
            while (true)
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
            if (operationResponse.OperationCode == 1)
            {
                ArrayList servers = (ArrayList)operationResponse.Parameters[2];
                Console.WriteLine("Response: " + (string)operationResponse.Parameters[1]);
                Console.WriteLine("New Airstrike servers list");
                foreach (Dictionary<String, String> data in servers)
                {
                    foreach (KeyValuePair<String, String> pair in data)
                    {
                        Console.Write("[{0}={1}] ", pair.Key, pair.Value);
                    }
                    Console.WriteLine();
                }
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
