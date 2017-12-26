namespace Flughafenprogramm
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.addterminalbtn = new System.Windows.Forms.Button();
            this.listView1 = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listView2 = new System.Windows.Forms.ListView();
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label11 = new System.Windows.Forms.Label();
            this.addflight = new System.Windows.Forms.Button();
            this.editflight = new System.Windows.Forms.Button();
            this.deleteflight = new System.Windows.Forms.Button();
            this.addpassenger = new System.Windows.Forms.Button();
            this.editpassenger = new System.Windows.Forms.Button();
            this.deletepassenger = new System.Windows.Forms.Button();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // addterminalbtn
            // 
            this.addterminalbtn.AutoSize = true;
            this.addterminalbtn.BackColor = System.Drawing.SystemColors.Control;
            this.addterminalbtn.Location = new System.Drawing.Point(10, 528);
            this.addterminalbtn.Name = "addterminalbtn";
            this.addterminalbtn.Size = new System.Drawing.Size(105, 34);
            this.addterminalbtn.TabIndex = 0;
            this.addterminalbtn.Text = "Add Terminal";
            this.addterminalbtn.UseVisualStyleBackColor = false;
            this.addterminalbtn.Click += new System.EventHandler(this.button1_Click);
            // 
            // listView1
            // 
            this.listView1.BackColor = System.Drawing.SystemColors.Window;
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4});
            this.listView1.ForeColor = System.Drawing.SystemColors.WindowText;
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.Location = new System.Drawing.Point(21, 65);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(544, 174);
            this.listView1.TabIndex = 9;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.DoubleClick += new System.EventHandler(this.doubleclick);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Nummer";
            this.columnHeader1.Width = 81;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Ziel";
            this.columnHeader2.Width = 70;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Anzahl Gepaeckstuecke";
            this.columnHeader3.Width = 160;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Max. Gewicht";
            this.columnHeader4.Width = 95;
            // 
            // listView2
            // 
            this.listView2.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8});
            this.listView2.FullRowSelect = true;
            this.listView2.GridLines = true;
            this.listView2.Location = new System.Drawing.Point(21, 301);
            this.listView2.MultiSelect = false;
            this.listView2.Name = "listView2";
            this.listView2.Size = new System.Drawing.Size(544, 166);
            this.listView2.TabIndex = 11;
            this.listView2.UseCompatibleStateImageBehavior = false;
            this.listView2.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Nummer";
            this.columnHeader5.Width = 71;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Nachname";
            this.columnHeader6.Width = 82;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Vorname";
            this.columnHeader7.Width = 72;
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Flugnummer";
            this.columnHeader8.Width = 92;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label5.Location = new System.Drawing.Point(22, 39);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(50, 20);
            this.label5.TabIndex = 17;
            this.label5.Text = "Flüge";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label6.Location = new System.Drawing.Point(22, 278);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(93, 20);
            this.label6.TabIndex = 18;
            this.label6.Text = "Passagiere";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.panel2.Controls.Add(this.label11);
            this.panel2.Location = new System.Drawing.Point(-3, -5);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(851, 35);
            this.panel2.TabIndex = 30;
            this.panel2.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel2_MouseDown);
            this.panel2.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel2_MouseMove);
            this.panel2.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel2_MouseUp);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label11.Location = new System.Drawing.Point(4, 11);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(61, 17);
            this.label11.TabIndex = 0;
            this.label11.Text = "Zentrale";
            // 
            // addflight
            // 
            this.addflight.Location = new System.Drawing.Point(274, 245);
            this.addflight.Name = "addflight";
            this.addflight.Size = new System.Drawing.Size(100, 33);
            this.addflight.TabIndex = 31;
            this.addflight.Text = "Hinzufügen";
            this.addflight.UseVisualStyleBackColor = true;
            this.addflight.Click += new System.EventHandler(this.addflight_Click);
            // 
            // editflight
            // 
            this.editflight.Location = new System.Drawing.Point(380, 245);
            this.editflight.Name = "editflight";
            this.editflight.Size = new System.Drawing.Size(94, 33);
            this.editflight.TabIndex = 32;
            this.editflight.Text = "Bearbeiten";
            this.editflight.UseVisualStyleBackColor = true;
            // 
            // deleteflight
            // 
            this.deleteflight.Location = new System.Drawing.Point(480, 245);
            this.deleteflight.Name = "deleteflight";
            this.deleteflight.Size = new System.Drawing.Size(85, 33);
            this.deleteflight.TabIndex = 33;
            this.deleteflight.Text = "Löschen";
            this.deleteflight.UseVisualStyleBackColor = true;
            // 
            // addpassenger
            // 
            this.addpassenger.Location = new System.Drawing.Point(274, 475);
            this.addpassenger.Name = "addpassenger";
            this.addpassenger.Size = new System.Drawing.Size(100, 33);
            this.addpassenger.TabIndex = 34;
            this.addpassenger.Text = "Hinzufügen";
            this.addpassenger.UseVisualStyleBackColor = true;
            this.addpassenger.Click += new System.EventHandler(this.addpassenger_Click);
            // 
            // editpassenger
            // 
            this.editpassenger.Location = new System.Drawing.Point(380, 475);
            this.editpassenger.Name = "editpassenger";
            this.editpassenger.Size = new System.Drawing.Size(94, 33);
            this.editpassenger.TabIndex = 35;
            this.editpassenger.Text = "Bearbeiten";
            this.editpassenger.UseVisualStyleBackColor = true;
            // 
            // deletepassenger
            // 
            this.deletepassenger.Location = new System.Drawing.Point(480, 475);
            this.deletepassenger.Name = "deletepassenger";
            this.deletepassenger.Size = new System.Drawing.Size(85, 33);
            this.deletepassenger.TabIndex = 36;
            this.deletepassenger.Text = "Löschen";
            this.deletepassenger.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.ClientSize = new System.Drawing.Size(970, 730);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button addterminalbtn;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ListView listView2;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button addflight;
        private System.Windows.Forms.Button editflight;
        private System.Windows.Forms.Button deleteflight;
        private System.Windows.Forms.Button addpassenger;
        private System.Windows.Forms.Button editpassenger;
        private System.Windows.Forms.Button deletepassenger;
        private PassengerControl passengerControl1;
    }
}

