using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{
    public class Gyro
    {
        public Data X { get; set; }
        public Data Y { get; set; }
        public Data Z { get; set; }
        public List<Data> listGyro { get; set; }

        public Gyro()
        {
            X = new Data("X");
            Y = new Data("Y");
            Z = new Data("Z");
            listGyro = new List<Data>();
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
            }
        }
        public void packData()
        {
            if (listGyro.Count == 0)
            {
                listGyro.Add(X);
                listGyro.Add(Y);
                listGyro.Add(Z);
            }
        }
    }

   
}
