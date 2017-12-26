namespace Flughafenprogramm
{
    partial class PassengerControl
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

        #region Vom Komponenten-Designer generierter Code

        /// <summary> 
        /// Erforderliche Methode für die Designerunterstützung. 
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.id = new System.Windows.Forms.TextBox();
            this.lastname = new System.Windows.Forms.TextBox();
            this.firstname = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.familymemberlist = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label5 = new System.Windows.Forms.Label();
            this.familiymember = new System.Windows.Forms.ComboBox();
            this.addfamilymember = new System.Windows.Forms.Button();
            this.okbtn = new System.Windows.Forms.Button();
            this.abortbtn = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.flight = new System.Windows.Forms.ComboBox();
            this.deletefamilymember = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // id
            // 
            this.id.Location = new System.Drawing.Point(6, 20);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(137, 22);
            this.id.TabIndex = 0;
            // 
            // lastname
            // 
            this.lastname.Location = new System.Drawing.Point(6, 65);
            this.lastname.Name = "lastname";
            this.lastname.Size = new System.Drawing.Size(137, 22);
            this.lastname.TabIndex = 1;
            // 
            // firstname
            // 
            this.firstname.Location = new System.Drawing.Point(6, 110);
            this.firstname.Name = "firstname";
            this.firstname.Size = new System.Drawing.Size(137, 22);
            this.firstname.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Nummer";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label4.Location = new System.Drawing.Point(3, 222);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 17);
            this.label4.TabIndex = 5;
            this.label4.Text = "Flug";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label3.Location = new System.Drawing.Point(3, 90);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Vorname";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label2.Location = new System.Drawing.Point(3, 45);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 17);
            this.label2.TabIndex = 7;
            this.label2.Text = "Nachname";
            // 
            // familymemberlist
            // 
            this.familymemberlist.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.familymemberlist.GridLines = true;
            this.familymemberlist.Location = new System.Drawing.Point(174, 20);
            this.familymemberlist.Name = "familymemberlist";
            this.familymemberlist.Size = new System.Drawing.Size(369, 144);
            this.familymemberlist.TabIndex = 8;
            this.familymemberlist.UseCompatibleStateImageBehavior = false;
            this.familymemberlist.View = System.Windows.Forms.View.Details;
            this.familymemberlist.SelectedIndexChanged += new System.EventHandler(this.familymemberlist_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Nummer";
            this.columnHeader1.Width = 92;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Nachname";
            this.columnHeader2.Width = 93;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Vorname";
            this.columnHeader3.Width = 89;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label5.Location = new System.Drawing.Point(171, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(121, 17);
            this.label5.TabIndex = 9;
            this.label5.Text = "Familienmitglieder";
            // 
            // familiymember
            // 
            this.familiymember.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.familiymember.FormattingEnabled = true;
            this.familiymember.Location = new System.Drawing.Point(6, 191);
            this.familiymember.Name = "familiymember";
            this.familiymember.Size = new System.Drawing.Size(297, 24);
            this.familiymember.TabIndex = 10;
            this.familiymember.Click += new System.EventHandler(this.familiymember_Click);
            // 
            // addfamilymember
            // 
            this.addfamilymember.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.addfamilymember.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.addfamilymember.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.addfamilymember.Location = new System.Drawing.Point(309, 191);
            this.addfamilymember.Name = "addfamilymember";
            this.addfamilymember.Size = new System.Drawing.Size(90, 30);
            this.addfamilymember.TabIndex = 11;
            this.addfamilymember.Text = "hinzufügen";
            this.addfamilymember.UseVisualStyleBackColor = false;
            this.addfamilymember.Click += new System.EventHandler(this.addfamilymember_Click);
            // 
            // okbtn
            // 
            this.okbtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.okbtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.okbtn.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.okbtn.Location = new System.Drawing.Point(366, 290);
            this.okbtn.Name = "okbtn";
            this.okbtn.Size = new System.Drawing.Size(75, 23);
            this.okbtn.TabIndex = 12;
            this.okbtn.Text = "OK";
            this.okbtn.UseVisualStyleBackColor = false;
            this.okbtn.Click += new System.EventHandler(this.okbtn_Click);
            // 
            // abortbtn
            // 
            this.abortbtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.abortbtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.abortbtn.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.abortbtn.Location = new System.Drawing.Point(447, 290);
            this.abortbtn.Name = "abortbtn";
            this.abortbtn.Size = new System.Drawing.Size(96, 23);
            this.abortbtn.TabIndex = 13;
            this.abortbtn.Text = "Abbrechen";
            this.abortbtn.UseVisualStyleBackColor = false;
            this.abortbtn.Click += new System.EventHandler(this.abortbtn_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label6.Location = new System.Drawing.Point(3, 171);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(108, 17);
            this.label6.TabIndex = 14;
            this.label6.Text = "Familienmitglied";
            // 
            // flight
            // 
            this.flight.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.flight.FormattingEnabled = true;
            this.flight.Location = new System.Drawing.Point(6, 242);
            this.flight.Name = "flight";
            this.flight.Size = new System.Drawing.Size(297, 24);
            this.flight.TabIndex = 15;
            // 
            // deletefamilymember
            // 
            this.deletefamilymember.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.deletefamilymember.Enabled = false;
            this.deletefamilymember.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.deletefamilymember.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.deletefamilymember.Location = new System.Drawing.Point(405, 191);
            this.deletefamilymember.Name = "deletefamilymember";
            this.deletefamilymember.Size = new System.Drawing.Size(98, 30);
            this.deletefamilymember.TabIndex = 16;
            this.deletefamilymember.Text = "entfernen";
            this.deletefamilymember.UseVisualStyleBackColor = false;
            this.deletefamilymember.Click += new System.EventHandler(this.deletefamilymember_Click);
            // 
            // PassengerControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.Controls.Add(this.deletefamilymember);
            this.Controls.Add(this.flight);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.abortbtn);
            this.Controls.Add(this.okbtn);
            this.Controls.Add(this.addfamilymember);
            this.Controls.Add(this.familiymember);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.familymemberlist);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.firstname);
            this.Controls.Add(this.lastname);
            this.Controls.Add(this.id);
            this.Name = "PassengerControl";
            this.Size = new System.Drawing.Size(571, 316);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox id;
        private System.Windows.Forms.TextBox lastname;
        private System.Windows.Forms.TextBox firstname;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListView familymemberlist;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox familiymember;
        private System.Windows.Forms.Button addfamilymember;
        private System.Windows.Forms.Button okbtn;
        private System.Windows.Forms.Button abortbtn;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox flight;
        private System.Windows.Forms.Button deletefamilymember;
    }
}
