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
    public partial class Form1 : Form
    {
        private List<Form> terminals;
        private List<Flug> fluege;
        private char[] charsToTrim;
        private bool tgl = false;
        List<char> clist;

        public Form1()
        {
            InitializeComponent();
            terminals = new List<Form>();
            fluege = new List<Flug>();
            clist = new List<char>();

            for(char i = (char)0; i<0xFF; i++)
            {
                if(!char.IsLetter(i) && !char.IsNumber(i))
                {
                    clist.Add(i);
                }
            }
            charsToTrim = clist.ToArray();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (terminals.Count < 10)
            {
                Form t = new Terminal();
                terminals.Add(t);
                t.Show();
                t.FormClosed += T_FormClosed;
            }
            else
            {
                MessageBox.Show("Es können maximal nur 10 Terminals angelegt werden!");
            }
            
        }

        private void T_FormClosed(object sender, FormClosedEventArgs e)
        {
            terminals.Remove((Form)sender);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            //Flug f;
            //int num;
            //int anzgep;
            //int gew;
            //if (textBox2.Text.Trim(charsToTrim).Length > 1 && int.TryParse(textBox1.Text, out num) && int.TryParse(textBox3.Text, out anzgep) && int.TryParse(textBox4.Text, out gew))
            //{
            //    if (!CheckFluege(num))
            //    {
            //        MessageBox.Show("Flug mit Nummer " + num + " ist bereits vorhanden!");
            //        return;
            //    }

            //    if (!CheckGepaeck(anzgep))
            //    {
            //        MessageBox.Show("Ungültige Eingabe für die Anzahl der Gepäckstücke! Die Anzahl der Gepäckstücke muss im Bereich 1 - 10 liegen!");
            //        return;
            //    }

            //    if (!CheckGewicht(gew))
            //    {
            //        MessageBox.Show("Ungültige Eingabe für das maximal Gewicht! Gewicht muss im Bereich 1 - 100 liegen!");
            //        return;
            //    }


            //    f = new Flug(num, textBox2.Text, anzgep, gew);
            //            fluege.Add(f);
            //            ListViewItem lvi = new ListViewItem(num.ToString());
            //            lvi.SubItems.Add(textBox2.Text.Trim(charsToTrim));
            //            lvi.SubItems.Add(anzgep.ToString());
            //            lvi.SubItems.Add(gew.ToString());
            //            listView1.Items.Add(lvi);


            //}
            //else
            //{
            //    MessageBox.Show("Ungültiger Datensatz!");
            //}
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private bool CheckFluege(int nummer)
        {
            bool ret = true;
            for(int i = 0; i < fluege.Count(); i++)
            {
                if (fluege[i].GetNummer() == nummer)
                    ret = false;
            }
            return ret;
        }

        private bool CheckGepaeck(int anzgep)
        {
            if (anzgep > 10 || anzgep < 1)
                return false;
            else
                return true;
        }

        private bool CheckGewicht(int gew)
        {
            if (gew > 100 || gew < 1)
                return false;
            else
                return true;
        }

        private void doubleclick(object sender, EventArgs e)
        {
            
            MessageBox.Show("Nummer: " + ((ListView)sender).SelectedItems[0].Text + "\n" + "Ziel: " + ((ListView)sender).SelectedItems[0].SubItems[1].Text);
            
        }



        private void button2_Click_1(object sender, EventArgs e)
        {

        }


        bool mouseDown = false;

        private void panel2_MouseDown(object sender, MouseEventArgs e)
        {
            mouseDown = true;
        }

        private void panel2_MouseUp(object sender, MouseEventArgs e)
        {
            mouseDown = false;
        }

        private void panel2_MouseMove(object sender, MouseEventArgs e)
        {
            if (mouseDown)
            {
                this.SetDesktopLocation(MousePosition.X-200 , MousePosition.Y-10);
            }
        }

        bool cl = false;
        int prevbnds;
        int prevpanbnds;
        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void addpassenger_Click(object sender, EventArgs e)
        {
            
            if (!cl)
            {
                passengerControl1.Show();
                prevbnds = this.Bounds.Width;
                prevpanbnds = panel2.Bounds.Width;
                this.SetBounds(this.Bounds.X, this.Bounds.Y, 880, this.Bounds.Height);
                panel2.SetBounds(panel2.Bounds.X, panel2.Bounds.Y, 1000, panel2.Bounds.Height);
            }
            else
            {
                passengerControl1.Hide();
                this.SetBounds(this.Bounds.X, this.Bounds.Y, prevbnds, this.Bounds.Height);
                panel2.SetBounds(panel2.Bounds.X, panel2.Bounds.Y, prevpanbnds, panel2.Bounds.Height);
            }
            cl = !cl;
        }

        private void addflight_Click(object sender, EventArgs e)
        {

        }
    }
}
