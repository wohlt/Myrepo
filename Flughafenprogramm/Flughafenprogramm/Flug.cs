using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flughafenprogramm
{
    public class Flug
    {
        private int nummer;
        private string ziel;
        private int anzgepaeckstuecke;
        private int maxgew;

        public Flug(int num, string _ziel,int anzgep,int _maxgew)
        {
            nummer = num;
            ziel = _ziel;
            anzgepaeckstuecke = anzgep;
            maxgew = _maxgew;
        }

        public int GetNummer() { return nummer; }
        public string GetZiel() { return ziel; }
        public int GetAnzGepaeckstuecke() { return anzgepaeckstuecke; }
        public int GetMaxGewicht() { return maxgew; }
    }
}
