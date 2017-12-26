using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flughafenprogramm
{
    public class Passagier
    {
        private int nummer;
        private string Vorname;
        private string Nachname;
        private List<Passagier>familymember;
    //    private Flug flug;

        public Passagier(int num, string lname, string fname,List<Passagier> _familymember)
        {
            nummer = num;
            Vorname = fname;
            Nachname = lname;
            familymember = _familymember;
        }

        public int GetNummer() { return nummer; }
        public string GetVorname() { return Vorname; }
        public string GetNachname() { return Nachname; }
        public List<Passagier> GetFamilyMember() { return familymember; }
        public  void AddFamilyMember(Passagier p)
        {
            if (!familymember.Contains(p))
            {
                familymember.Add(p);
            }
        }
    //    public int GetMaxGewicht() { return maxgew; }
    }
}
