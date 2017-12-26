namespace Flughafenprogramm
{
    partial class GroupAssistant
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
            this.deletefamilymember = new System.Windows.Forms.Button();
            this.addfamilymember = new System.Windows.Forms.Button();
            this.familiymember = new System.Windows.Forms.ComboBox();
            this.familymemberlist = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.okbtn = new System.Windows.Forms.Button();
            this.abortbtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // deletefamilymember
            // 
            this.deletefamilymember.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.deletefamilymember.Enabled = false;
            this.deletefamilymember.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.deletefamilymember.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.deletefamilymember.Location = new System.Drawing.Point(111, 218);
            this.deletefamilymember.Name = "deletefamilymember";
            this.deletefamilymember.Size = new System.Drawing.Size(98, 30);
            this.deletefamilymember.TabIndex = 20;
            this.deletefamilymember.Text = "entfernen";
            this.deletefamilymember.UseVisualStyleBackColor = false;
            this.deletefamilymember.Click += new System.EventHandler(this.deletefamilymember_Click);
            // 
            // addfamilymember
            // 
            this.addfamilymember.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.addfamilymember.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.addfamilymember.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.addfamilymember.Location = new System.Drawing.Point(15, 218);
            this.addfamilymember.Name = "addfamilymember";
            this.addfamilymember.Size = new System.Drawing.Size(90, 30);
            this.addfamilymember.TabIndex = 19;
            this.addfamilymember.Text = "hinzufügen";
            this.addfamilymember.UseVisualStyleBackColor = false;
            // 
            // familiymember
            // 
            this.familiymember.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.familiymember.FormattingEnabled = true;
            this.familiymember.Location = new System.Drawing.Point(15, 178);
            this.familiymember.Name = "familiymember";
            this.familiymember.Size = new System.Drawing.Size(430, 24);
            this.familiymember.TabIndex = 18;
            // 
            // familymemberlist
            // 
            this.familymemberlist.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.familymemberlist.GridLines = true;
            this.familymemberlist.Location = new System.Drawing.Point(15, 15);
            this.familymemberlist.Name = "familymemberlist";
            this.familymemberlist.Size = new System.Drawing.Size(430, 144);
            this.familymemberlist.TabIndex = 17;
            this.familymemberlist.UseCompatibleStateImageBehavior = false;
            this.familymemberlist.View = System.Windows.Forms.View.Details;
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
            // okbtn
            // 
            this.okbtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.okbtn.Enabled = false;
            this.okbtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.okbtn.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.okbtn.Location = new System.Drawing.Point(243, 218);
            this.okbtn.Name = "okbtn";
            this.okbtn.Size = new System.Drawing.Size(98, 30);
            this.okbtn.TabIndex = 21;
            this.okbtn.Text = "OK";
            this.okbtn.UseVisualStyleBackColor = false;
            // 
            // abortbtn
            // 
            this.abortbtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(122)))), ((int)(((byte)(204)))));
            this.abortbtn.Enabled = false;
            this.abortbtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.abortbtn.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.abortbtn.Location = new System.Drawing.Point(347, 218);
            this.abortbtn.Name = "abortbtn";
            this.abortbtn.Size = new System.Drawing.Size(98, 30);
            this.abortbtn.TabIndex = 22;
            this.abortbtn.Text = "Abbrechen";
            this.abortbtn.UseVisualStyleBackColor = false;
            // 
            // GroupAssistant
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(62)))), ((int)(((byte)(62)))), ((int)(((byte)(66)))));
            this.Controls.Add(this.abortbtn);
            this.Controls.Add(this.okbtn);
            this.Controls.Add(this.deletefamilymember);
            this.Controls.Add(this.addfamilymember);
            this.Controls.Add(this.familiymember);
            this.Controls.Add(this.familymemberlist);
            this.Name = "GroupAssistant";
            this.Size = new System.Drawing.Size(458, 263);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button deletefamilymember;
        private System.Windows.Forms.Button addfamilymember;
        private System.Windows.Forms.ComboBox familiymember;
        private System.Windows.Forms.ListView familymemberlist;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.Button okbtn;
        private System.Windows.Forms.Button abortbtn;
    }
}
