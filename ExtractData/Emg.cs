using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{
    public class Emg
    {
        public Data emg1 { get; set; }
        public Data emg2 { get; set; }
        public Data emg3 { get; set; }
        public Data emg4 { get; set; }
        public Data emg5 { get; set; }
        public Data emg6 { get; set; }
        public Data emg7 { get; set; }
        public Data emg8 { get; set; }

        public Emg()
        {
            emg1 = new Data("emg1");
            emg2 = new Data("emg2");
            emg3 = new Data("emg3");
            emg4 = new Data("emg4");
            emg5 = new Data("emg5");
            emg6 = new Data("emg6");
            emg7 = new Data("emg7");
            emg8 = new Data("emg8");
        }

        public void addData(int pos, int data)
        {
            switch (pos)
            {
                case 0:
                    emg1.addData(data);
                    break;
                case 1:
                    emg2.addData(data);
                    break;
                case 2:
                    emg3.addData(data);
                    break;
                case 3:
                    emg4.addData(data);
                    break;
                case 4:
                    emg5.addData(data);
                    break;
                case 5:
                    emg6.addData(data);
                    break;
                case 6:
                    emg7.addData(data);
                    break;
                case 7:
                    emg8.addData(data);
                    break;
            }
        }


    }
}
