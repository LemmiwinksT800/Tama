using Microsoft.VisualBasic.Logging;
using System.Diagnostics;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace WinApp
{
    public partial class MainForm : Form
    {
        private bool isConnected;
        private TcpClient? client;
        private NetworkStream? stream;
        private Process pythonScript;
        private string[] ports = SerialPort.GetPortNames();

        public MainForm()
        {
            InitializeComponent();
            btnPing.Enabled = false;
            COMPorts.Items.AddRange(ports);
        }

        private async void btnConnect_Click(object sender, EventArgs e)
        {
            await ConnectToBoard();
        }
        private void Log(string message)
        {
            txtLog.AppendText(DateTime.Now.ToLongTimeString() + (' ' + message) + Environment.NewLine);
        }

        private async void btnDisconnect_Click(object sender, EventArgs e)
        {
            await DisconnectFromBoard();
        }
        private async Task ConnectToBoard()
        {
            try
            {
                if (COMPorts.SelectedItem == null)
                {
                    Log("Choose the COM port");
                    return;
                }
                COMPortBoxLabel.Text = "COM port is";
                var selectedSerial = COMPorts.SelectedItem.ToString();

                pythonScript = new Process();
                var pythonScriptStartInfo = new ProcessStartInfo();
                pythonScript.StartInfo = pythonScriptStartInfo;
                pythonScriptStartInfo.FileName = @"python";
                pythonScriptStartInfo.WorkingDirectory = AppDomain.CurrentDomain.BaseDirectory;
                pythonScriptStartInfo.Arguments = $@"..\..\..\..\..\pc_soft\Client.py {selectedSerial}";
                pythonScriptStartInfo.RedirectStandardOutput = true;
                pythonScriptStartInfo.RedirectStandardError = true;
                pythonScriptStartInfo.UseShellExecute = false;
                pythonScriptStartInfo.CreateNoWindow = true;
                pythonScript.Start();

                await Task.Run(async () =>
                {
                    string line;
                    while ((line = await pythonScript.StandardOutput.ReadLineAsync()) != null)
                    {
                        if (line.Contains("READY")) break;
                    }
                });
                

                client = new TcpClient();
                await client.ConnectAsync("127.0.0.1", 5000);
                stream = client.GetStream();

                Log("Connecting to the service");
                isConnected = true;
                btnConnect.Enabled = false;
                btnDisconnect.Enabled = true;
                btnPing.Enabled = true;
                Log("Connected to service");
                Log("recognition started");
                lblStatus.Text = "Connected";
                _ =  ReceiveLoop();

            }
            catch (SocketException)
            {
                lblStatus.Text = "Error";
                Log("Bad socket error");
            }
            catch
            {
                lblStatus.Text = "Error";
                Log("Unknown Error");
            }
        }
        private async Task DisconnectFromBoard()
        {
            await SendCommand("EXIT");
            await Task.Delay(1000);
            if (pythonScript != null && !pythonScript.HasExited)
            {
                pythonScript.Dispose();
                pythonScript = null;
                Log("recognition stopped");
            } 
            if (client == null || stream == null)
            {
                lblStatus.Text = "Error";
                Log("Service is not connected");
                return;
            }
            stream.Close();
            client.Close();

            isConnected = false;
            btnDisconnect.Enabled = false;
            await Task.Delay(1000);
            btnConnect.Enabled = true;
            btnPing.Enabled= false;
            Log("Disconnected from service");
            lblStatus.Text = "Disconnected";

            stream = null;
            client = null;

       
        }
        private async Task SendCommand(string command)
        {
            if (stream == null)
            {
                Log("Stream Error");
                return;
            }
            byte[] data = Encoding.UTF8.GetBytes(command + '\n');
            await stream.WriteAsync(data, 0, data.Length);
        }

        private async void btnPing_Click(object sender, EventArgs e)
        {
            await SendCommand("PING!");
            Log("Sent: PING!");
        }
        private async Task ReceiveLoop()
        {
            var sr = new StreamReader(stream);
            string message;
            while ((message = await sr.ReadLineAsync()) != null)
            {
                Log(String.Format("Received: {0}", message));
            }
            Log("Connection closed by service");
            sr.Close();
        }
    }
}
