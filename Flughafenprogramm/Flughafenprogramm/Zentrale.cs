using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Flughafenprogramm
{
    public partial class Zentrale : Form
    {
        private List<Form> terminals;

        public event EventHandler AddPassenger;

        public Zentrale()
        {
            InitializeComponent();
            passengerControl1.AddZentrale(this);
            Database.InitDatabase();
            passengerControl1.PassengerControlOK += PassengerControl1_PassengerControlOK;
            passengerControl1.PassengerControlAbort += PassengerControl1_PassengerControlAbort;
        }

        private void PassengerControl1_PassengerControlAbort(object sender, EventArgs e)
        {
            actionlabel.Hide();
            cl = !cl;
            addpassenger.Enabled = true;
            addflight.Enabled = true;
            passengerControl1.Hide();
            this.SetBounds(this.Bounds.X, this.Bounds.Y, prevbnds, this.Bounds.Height);
            panel1.SetBounds(panel1.Bounds.X, panel1.Bounds.Y, prevpanbnds, panel1.Bounds.Height);
        }

        private void UpdatePassengerView()
        {
            listView2.Items.Clear();
            foreach (Passagier p in Database.GetPassenger())
            {
                ListViewItem lvi = new ListViewItem(p.GetNummer().ToString());
                lvi.SubItems.Add(p.GetNachname());
                lvi.SubItems.Add(p.GetVorname());
                listView2.Items.Add(lvi);
            }
        }

        private void PassengerControl1_PassengerControlOK(object sender, PassagierEventArgs e)
        {
            //passengers.Add(e.GetPassenger());
            UpdatePassengerView();
            actionlabel.Hide();
            cl = !cl;
            addpassenger.Enabled = true;
            addflight.Enabled = true;
            passengerControl1.Hide();
            this.SetBounds(this.Bounds.X, this.Bounds.Y, prevbnds, this.Bounds.Height);
            panel1.SetBounds(panel1.Bounds.X, panel1.Bounds.Y, prevpanbnds, panel1.Bounds.Height);
        }

        bool mouseDown = false;

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
           mouseDown = true;
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            mouseDown = false;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (mouseDown)
            {
                this.SetDesktopLocation(MousePosition.X - 200, MousePosition.Y - 10);
            }
        }



        private void button2_Click(object sender, EventArgs e)
        {

        }


        private void addterminal_Click(object sender, EventArgs e)
        {

        }


        bool cl = false;
        bool c2 = false;
        int prevbnds;
        int prevpanbnds;

        private void addflight_Click(object sender, EventArgs e)
        {
 
            if (!c2)
            {
                flightlabel.Text = "Neuen Flug hinzufügen";
                flightlabel.Show();
                addpassenger.Enabled = false;
                flightControl1.Show();
                prevbnds = this.Bounds.Width;
                prevpanbnds = panel1.Bounds.Width;
                this.SetBounds(this.Bounds.X, this.Bounds.Y, 680, this.Bounds.Height);
                panel1.SetBounds(panel1.Bounds.X, panel1.Bounds.Y, 1000, panel1.Bounds.Height);
            }
            else
            {
                flightlabel.Hide();
                addpassenger.Enabled = true;
                flightControl1.Hide();
                this.SetBounds(this.Bounds.X, this.Bounds.Y, prevbnds, this.Bounds.Height);
                panel1.SetBounds(panel1.Bounds.X, panel1.Bounds.Y, prevpanbnds, panel1.Bounds.Height);
            }
            c2 = !c2;
        }

        private void editflight_Click(object sender, EventArgs e)
        {

        }

        private void deleteflight_Click(object sender, EventArgs e)
        {

        }

        private void deletepassenger_Click(object sender, EventArgs e)
        {

        }

        private void editpassenger_Click(object sender, EventArgs e)
        {
            
        }

        private void addpassenger_Click(object sender, EventArgs e)
        {
            AddPassenger?.Invoke(this,new EventArgs());
            actionlabel.Text = "Neuen Passagier hinzufügen";
            actionlabel.Show();
            if (!cl)
            {
                addflight.Enabled = false;
                addpassenger.Enabled = false;
                passengerControl1.Show();
                prevbnds = this.Bounds.Width;
                prevpanbnds = panel1.Bounds.Width;
                this.SetBounds(this.Bounds.X, this.Bounds.Y, 880, this.Bounds.Height);
                panel1.SetBounds(panel1.Bounds.X, panel1.Bounds.Y, 1000, panel1.Bounds.Height);
            }
            cl = !cl;
        }


        private void Zentrale_Load(object sender, EventArgs e)
        {

        }

        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.deletepassenger.Enabled = this.listView2.SelectedItems.Count > 0;
            this.editpassenger.Enabled = this.listView2.SelectedItems.Count > 0;
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

    }
}
