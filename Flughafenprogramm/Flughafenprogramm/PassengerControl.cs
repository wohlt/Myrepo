using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Flughafenprogramm
{
    public partial class PassengerControl : UserControl
    {
        Zentrale zentrale;

        public event EventHandler<PassagierEventArgs> PassengerControlOK;
        public event EventHandler PassengerControlAbort;

        private char[] charsToTrimNumber;
        private char[] charsToTrimString;
        List<char> clist;
        List<Passagier> plist;

        public void AddZentrale(Zentrale z)
        {
            zentrale = z;
            zentrale.AddPassenger += Zentrale_AddPassenger;
        }

        public PassengerControl()
        {
            InitializeComponent();
            clist = new List<char>();
            plist = new List<Passagier>();
            for (char i = (char)0; i < 0xFF; i++)
            {
                if (!char.IsNumber(i))
                {
                    clist.Add(i);
                }
            }
            charsToTrimNumber = clist.ToArray();
            clist.Clear();

            for (char i = (char)0; i < 0xFF; i++)
            {
                if (!char.IsLetter(i))
                {
                    clist.Add(i);
                }
            }
            charsToTrimString = clist.ToArray();
            clist.Clear();
        }

        private void Zentrale_AddPassenger(object sender, EventArgs e)
        {
            plist.Clear();
            familymemberlist.Items.Clear();
        }

        private void okbtn_Click(object sender, EventArgs e)
        {
            int num;
            string lname;
            string fname;
            if (!int.TryParse(id.Text, out num))
            {
                MessageBox.Show("Der Passagier benötigt eine gültige Nummer!");
                return;
            }
            if(Database.GetPassenger(num) != null)
            {
                MessageBox.Show("Es ist bereits ein Passagier mit der Nummer " + num + " vorhanden!");
                return;
            }
            if (!CheckName(lastname.Text,out lname))
            { 
                MessageBox.Show("Fehler bei Eingabe des Nachnamens!");
                return;
            }
            if (!CheckName(firstname.Text, out fname))
            {
                MessageBox.Show("Fehler bei Eingabe des Vornamens!");
                return;
            }

            Passagier p = new Passagier(num, lname, fname, new List<Passagier>(plist));
            plist.Add(p);
            foreach(Passagier pa in plist)
            {
                foreach(Passagier pb in plist)
                    if(pa != pb)
                         pa.AddFamilyMember(pb);
            }
            Database.PostPassenger(p);
            PassengerControlOK?.Invoke(this, new PassagierEventArgs(p));
            id.Text = "";
            firstname.Text = "";
            lastname.Text = "";
        }

        private void abortbtn_Click(object sender, EventArgs e)
        {
            id.Text = "";
            firstname.Text = "";
            lastname.Text = "";
            PassengerControlAbort?.Invoke(this, new EventArgs());
        }

        private bool CheckName(string name, out string s)
        {
            bool ret = false;
            if((s = name.Trim(charsToTrimString)).Length != 0)
            { ret = true; }
            return ret;
        }

        private void familiymember_Click(object sender, EventArgs e)
        {
            familiymember.Items.Clear();
            foreach (Passagier p in Database.GetPassenger())
            {
                familiymember.Items.Add(p.GetNummer()+ " " + p.GetNachname()+ " " + p.GetVorname());
            }
        }

        private void addfamilymember_Click(object sender, EventArgs e)
        {
            if (familiymember.SelectedIndex >= 0)
            {
                Passagier p = Database.GetPassenger()[familiymember.SelectedIndex];
                if (!plist.Contains(p))
                {
                    plist.Add(p);
                }
                else
                {
                    MessageBox.Show("Dieses Familienmitglied ist bereits vorhanden!");
                    return;
                }

                foreach(Passagier fm in p.GetFamilyMember())
                {
                    if (!plist.Contains(fm))
                    {
                        plist.Add(fm);
                    }
                }
                plist.Sort(delegate (Passagier x, Passagier y)
                {
                    return x.GetNummer().CompareTo(y.GetNummer());
                });

                familymemberlist.Items.Clear();
                foreach(Passagier pa in plist)
                {
                    ListViewItem lvi = new ListViewItem(pa.GetNummer().ToString());
                    lvi.SubItems.Add(pa.GetNachname());
                    lvi.SubItems.Add(pa.GetVorname());
                    familymemberlist.Items.Add(lvi);
                }
            }
        }

        private void familymemberlist_SelectedIndexChanged(object sender, EventArgs e)
        {
            deletefamilymember.Enabled = this.familymemberlist.SelectedItems.Count > 0;
        }

        private void deletefamilymember_Click(object sender, EventArgs e)
        {
            foreach( ListViewItem l in familymemberlist.SelectedItems)
            {
                plist.Remove(plist[l.Index]);
                l.Remove();
            }

        }
    }
}
