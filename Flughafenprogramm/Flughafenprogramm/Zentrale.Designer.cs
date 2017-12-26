namespace Flughafenprogramm
{
    partial class Zentrale
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.listView1 = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label2 = new System.Windows.Forms.Label();
            this.listView2 = new System.Windows.Forms.ListView();
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label3 = new System.Windows.Forms.Label();
            this.addpassenger = new System.Windows.Forms.Button();
            this.editpassenger = new System.Windows.Forms.Button();
            this.deletepassenger = new System.Windows.Forms.Button();
            this.deleteflight = new System.Windows.Forms.Button();
            this.editflight = new System.Windows.Forms.Button();
            this.addflight = new System.Windows.Forms.Button();
            this.addterminal = new System.Windows.Forms.Button();
            this.flightControl1 = new Flughafenprogramm.FlightControl();
            this.passengerControl1 = new Flughafenprogramm.PassengerControl();
            this.label4 = new System.Windows.Forms.Label();
            this.actionlabel = new System.Windows.Forms.Label();
            this.flightlabel = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(1, 1);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(850, 28);
            this.panel1.TabIndex = 0;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(3, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Zentrale";
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4});
            this.listView1.GridLines = true;
            this.listView1.Location = new System.Drawing.Point(12, 69);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(538, 149);
            this.listView1.TabIndex = 1;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Nummer";
            this.columnHeader1.Width = 70;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Ziel";
            this.columnHeader2.Width = 96;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Anz. Gepäckstücke";
            this.columnHeader3.Width = 152;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Max. Gewicht";
            this.columnHeader4.Width = 117;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label2.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label2.Location = new System.Drawing.Point(12, 39);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Flüge";
            // 
            // listView2
            // 
            this.listView2.Activation = System.Windows.Forms.ItemActivation.OneClick;
            this.listView2.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8});
            this.listView2.FullRowSelect = true;
            this.listView2.GridLines = true;
            this.listView2.Location = new System.Drawing.Point(12, 300);
            this.listView2.MultiSelect = false;
            this.listView2.Name = "listView2";
            this.listView2.Size = new System.Drawing.Size(538, 149);
            this.listView2.TabIndex = 3;
            this.listView2.UseCompatibleStateImageBehavior = false;
            this.listView2.View = System.Windows.Forms.View.Details;
            this.listView2.SelectedIndexChanged += new System.EventHandler(this.listView2_SelectedIndexChanged);
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Nummer";
            this.columnHeader5.Width = 70;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Nachname";
            this.columnHeader6.Width = 96;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Vorname";
            this.columnHeader7.Width = 132;
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Flugnummer";
            this.columnHeader8.Width = 139;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label3.Location = new System.Drawing.Point(15, 268);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(93, 20);
            this.label3.TabIndex = 4;
            this.label3.Text = "Passagiere";
            // 
            // addpassenger
            // 
            this.addpassenger.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.addpassenger.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.addpassenger.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.addpassenger.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.addpassenger.Location = new System.Drawing.Point(222, 455);
            this.addpassenger.Name = "addpassenger";
            this.addpassenger.Size = new System.Drawing.Size(117, 26);
            this.addpassenger.TabIndex = 5;
            this.addpassenger.Text = "Hinzufügen";
            this.addpassenger.UseVisualStyleBackColor = false;
            this.addpassenger.Click += new System.EventHandler(this.addpassenger_Click);
            // 
            // editpassenger
            // 
            this.editpassenger.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.editpassenger.Enabled = false;
            this.editpassenger.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.editpassenger.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.editpassenger.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.editpassenger.Location = new System.Drawing.Point(345, 455);
            this.editpassenger.Name = "editpassenger";
            this.editpassenger.Size = new System.Drawing.Size(105, 26);
            this.editpassenger.TabIndex = 6;
            this.editpassenger.Text = "Bearbeiten";
            this.editpassenger.UseVisualStyleBackColor = false;
            this.editpassenger.Click += new System.EventHandler(this.editpassenger_Click);
            // 
            // deletepassenger
            // 
            this.deletepassenger.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.deletepassenger.Enabled = false;
            this.deletepassenger.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.deletepassenger.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.deletepassenger.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.deletepassenger.Location = new System.Drawing.Point(456, 455);
            this.deletepassenger.Name = "deletepassenger";
            this.deletepassenger.Size = new System.Drawing.Size(94, 26);
            this.deletepassenger.TabIndex = 7;
            this.deletepassenger.Text = "Löschen";
            this.deletepassenger.UseVisualStyleBackColor = false;
            this.deletepassenger.Click += new System.EventHandler(this.deletepassenger_Click);
            // 
            // deleteflight
            // 
            this.deleteflight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.deleteflight.Enabled = false;
            this.deleteflight.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.deleteflight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.deleteflight.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.deleteflight.Location = new System.Drawing.Point(456, 224);
            this.deleteflight.Name = "deleteflight";
            this.deleteflight.Size = new System.Drawing.Size(94, 26);
            this.deleteflight.TabIndex = 10;
            this.deleteflight.Text = "Löschen";
            this.deleteflight.UseVisualStyleBackColor = false;
            this.deleteflight.Click += new System.EventHandler(this.deleteflight_Click);
            // 
            // editflight
            // 
            this.editflight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.editflight.Enabled = false;
            this.editflight.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.editflight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.editflight.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.editflight.Location = new System.Drawing.Point(345, 224);
            this.editflight.Name = "editflight";
            this.editflight.Size = new System.Drawing.Size(105, 26);
            this.editflight.TabIndex = 9;
            this.editflight.Text = "Bearbeiten";
            this.editflight.UseVisualStyleBackColor = false;
            this.editflight.Click += new System.EventHandler(this.editflight_Click);
            // 
            // addflight
            // 
            this.addflight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.addflight.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.addflight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.addflight.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.addflight.Location = new System.Drawing.Point(222, 224);
            this.addflight.Name = "addflight";
            this.addflight.Size = new System.Drawing.Size(117, 26);
            this.addflight.TabIndex = 8;
            this.addflight.Text = "Hinzufügen";
            this.addflight.UseVisualStyleBackColor = false;
            this.addflight.Click += new System.EventHandler(this.addflight_Click);
            // 
            // addterminal
            // 
            this.addterminal.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.addterminal.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.addterminal.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.addterminal.Location = new System.Drawing.Point(12, 497);
            this.addterminal.Name = "addterminal";
            this.addterminal.Size = new System.Drawing.Size(147, 32);
            this.addterminal.TabIndex = 11;
            this.addterminal.Text = "Neues Terminal";
            this.addterminal.UseVisualStyleBackColor = false;
            this.addterminal.Click += new System.EventHandler(this.addterminal_Click);
            // 
            // flightControl1
            // 
            this.flightControl1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.flightControl1.Location = new System.Drawing.Point(600, 139);
            this.flightControl1.Name = "flightControl1";
            this.flightControl1.Size = new System.Drawing.Size(312, 293);
            this.flightControl1.TabIndex = 12;
            this.flightControl1.Visible = false;
            // 
            // passengerControl1
            // 
            this.passengerControl1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.passengerControl1.Location = new System.Drawing.Point(600, 180);
            this.passengerControl1.Name = "passengerControl1";
            this.passengerControl1.Size = new System.Drawing.Size(582, 332);
            this.passengerControl1.TabIndex = 13;
            this.passengerControl1.Visible = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(597, 139);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 17);
            this.label4.TabIndex = 14;
            // 
            // actionlabel
            // 
            this.actionlabel.AutoSize = true;
            this.actionlabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.actionlabel.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.actionlabel.Location = new System.Drawing.Point(603, 126);
            this.actionlabel.Name = "actionlabel";
            this.actionlabel.Size = new System.Drawing.Size(53, 20);
            this.actionlabel.TabIndex = 15;
            this.actionlabel.Text = "label5";
            this.actionlabel.Visible = false;
            // 
            // flightlabel
            // 
            this.flightlabel.AutoSize = true;
            this.flightlabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.flightlabel.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.flightlabel.Location = new System.Drawing.Point(604, 101);
            this.flightlabel.Name = "flightlabel";
            this.flightlabel.Size = new System.Drawing.Size(53, 20);
            this.flightlabel.TabIndex = 16;
            this.flightlabel.Text = "label5";
            this.flightlabel.Visible = false;
            // 
            // Zentrale
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.ClientSize = new System.Drawing.Size(568, 543);
            this.Controls.Add(this.flightlabel);
            this.Controls.Add(this.actionlabel);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.passengerControl1);
            this.Controls.Add(this.flightControl1);
            this.Controls.Add(this.addterminal);
            this.Controls.Add(this.deleteflight);
            this.Controls.Add(this.editflight);
            this.Controls.Add(this.addflight);
            this.Controls.Add(this.deletepassenger);
            this.Controls.Add(this.editpassenger);
            this.Controls.Add(this.addpassenger);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.listView2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Zentrale";
            this.Text = "Zentrale";
            this.Load += new System.EventHandler(this.Zentrale_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button addpassenger;
        private System.Windows.Forms.Button editpassenger;
        private System.Windows.Forms.Button deletepassenger;
        private System.Windows.Forms.Button deleteflight;
        private System.Windows.Forms.Button editflight;
        private System.Windows.Forms.Button addflight;
        private System.Windows.Forms.Button addterminal;
        private FlightControl flightControl1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label actionlabel;
        private PassengerControl passengerControl1;
        private System.Windows.Forms.Label flightlabel;
        private System.Windows.Forms.ListView listView2;
    }
}