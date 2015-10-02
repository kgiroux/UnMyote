using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{
    public class Orientation
    {
        public Data X { get; set; }
        public Data Y { get; set; }
        public Data Z { get; set; }
        public Data W { get; set; }
        public List<Data> listOrientation { get; set; }
        public Orientation()
        {
            X = new Data("X");
            Y = new Data("Y");
            Z = new Data("Z");
            W = new Data("W");
            listOrientation = new List<Data>();
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
                case 3:
                    W.addData(data);
                    break;
            }
        }

        public void addDataByText(string text, double data)
        {
            switch (text)
            {
                case "X":
                    X.addData(data);
                    break;
                case "Y":
                    Y.addData(data);
                    break;
                case "Z":
                    Z.addData(data);
                    break;
                case "W":
                    W.addData(data);
                    break;
            }
        }

        public void packData()
        {
            if (listOrientation.Count == 0)
            {
                listOrientation.Add(X);
                listOrientation.Add(Y);
                listOrientation.Add(Z);
                listOrientation.Add(W);
            }
        }

    }
}
