namespace WinApp
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            btnConnect = new Button();
            txtLog = new TextBox();
            lblStatus = new Label();
            btnDisconnect = new Button();
            btnPing = new Button();
            COMPorts = new ComboBox();
            COMPortBoxLabel = new Label();
            SuspendLayout();
            // 
            // btnConnect
            // 
            btnConnect.Location = new Point(206, 284);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(94, 29);
            btnConnect.TabIndex = 0;
            btnConnect.Text = "Connect";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click;
            // 
            // txtLog
            // 
            txtLog.Location = new Point(167, 68);
            txtLog.Multiline = true;
            txtLog.Name = "txtLog";
            txtLog.ReadOnly = true;
            txtLog.ScrollBars = ScrollBars.Vertical;
            txtLog.Size = new Size(469, 73);
            txtLog.TabIndex = 1;
            // 
            // lblStatus
            // 
            lblStatus.AutoSize = true;
            lblStatus.Location = new Point(344, 226);
            lblStatus.Name = "lblStatus";
            lblStatus.Size = new Size(99, 20);
            lblStatus.TabIndex = 2;
            lblStatus.Text = "Disconnected";
            // 
            // btnDisconnect
            // 
            btnDisconnect.Location = new Point(478, 284);
            btnDisconnect.Name = "btnDisconnect";
            btnDisconnect.Size = new Size(94, 29);
            btnDisconnect.TabIndex = 3;
            btnDisconnect.Text = "Disconnect";
            btnDisconnect.UseVisualStyleBackColor = true;
            btnDisconnect.Click += btnDisconnect_Click;
            // 
            // btnPing
            // 
            btnPing.Location = new Point(335, 367);
            btnPing.Name = "btnPing";
            btnPing.Size = new Size(94, 29);
            btnPing.TabIndex = 4;
            btnPing.Text = "Ping";
            btnPing.UseVisualStyleBackColor = true;
            btnPing.Click += btnPing_Click;
            // 
            // COMPorts
            // 
            COMPorts.FormattingEnabled = true;
            COMPorts.Location = new Point(167, 147);
            COMPorts.Name = "COMPorts";
            COMPorts.Size = new Size(469, 28);
            COMPorts.TabIndex = 5;
            // 
            // COMPortBoxLabel
            // 
            COMPortBoxLabel.AutoSize = true;
            COMPortBoxLabel.Location = new Point(12, 150);
            COMPortBoxLabel.Name = "COMPortBoxLabel";
            COMPortBoxLabel.Size = new Size(150, 20);
            COMPortBoxLabel.TabIndex = 6;
            COMPortBoxLabel.Text = "Choose the COM Port";
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(801, 459);
            Controls.Add(COMPortBoxLabel);
            Controls.Add(COMPorts);
            Controls.Add(btnPing);
            Controls.Add(btnDisconnect);
            Controls.Add(lblStatus);
            Controls.Add(txtLog);
            Controls.Add(btnConnect);
            Name = "MainForm";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnConnect;
        private TextBox txtLog;
        private Label lblStatus;
        private Button btnDisconnect;
        private Button btnPing;
        private ComboBox COMPorts;
        private Label COMPortBoxLabel;
    }
}
