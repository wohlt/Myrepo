using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flughafenprogramm
{
    public class PassagierEventArgs : EventArgs
    {
    
       private Passagier passenger;
       public PassagierEventArgs(Passagier p) { passenger = p; }
        public Passagier GetPassenger() { return passenger; }
    }
}

