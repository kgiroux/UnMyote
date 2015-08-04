using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{
    public class Acce
    {
        public Data X { get; set; }
        public Data Y { get; set; }
        public Data Z { get; set; }
        public List<Data> listAccero { get; set; }
        public Acce()
        {
            X = new Data("X");
            Y = new Data("Y");
            Z = new Data("Z");
            listAccero = new List<Data>();
        }

        public void addData(int pos, double data)
        {
            switch (pos)
            {
                case 0:
                    X.addData(data);
                    break;
                case 1:
                    Y.addData(data);
                    break;
                case 2:
                    Z.addData(data);
                    break;
            }
        }
        public void packData()
        {
            if (listAccero.Count == 0)
            {
                listAccero.Add(X);
                listAccero.Add(Y);
                listAccero.Add(Z);
            }
        }
    }
}
