using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flughafenprogramm
{


    public static class Database
    {
        private static Dictionary<int,Passagier> passengers;
        private static Dictionary<int,Flug> fluege;

        public static void InitDatabase()
        {
            passengers = new Dictionary<int, Passagier>();
            fluege = new Dictionary<int, Flug>();
        }

        public static List<Passagier> GetPassenger()
        {
            return passengers.Values.ToList<Passagier>();
        }

        public static Passagier GetPassenger(int id)
        {
            if (passengers.ContainsKey(id))
            {
                return passengers[id];
            }
            else
                return null;
        }

        public static bool PostPassenger(Passagier p)
        {
            bool ret = false;
            if (!passengers.ContainsKey(p.GetNummer()))
            { 
                passengers[p.GetNummer()] = p;
                ret = true;
            }
            return ret;
        }

        public static void PutPassenger(Passagier p)
        {
            passengers[p.GetNummer()] = p;
        }

        public static void DeletePassenger(int id)
        {
            passengers.Remove(id);
        }
    }
}
