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

        public List<Data> listEMG { get; set; }

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
            listEMG = new List<Data>();
        }

        public void addData(int pos, double data)
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

        public void addDataByText(string text, double data)
        {
            switch (text)
            {
                case "emg1":
                    emg1.addData(data);
                    break;
                case "emg2":
                    emg2.addData(data);
                    break;
                case "emg3":
                    emg3.addData(data);
                    break;
                case "emg4":
                    emg4.addData(data);
                    break;
                case "emg5":
                    emg5.addData(data);
                    break;
                case "emg6":
                    emg6.addData(data);
                    break;
                case "emg7":
                    emg7.addData(data);
                    break;
                case "emg8":
                    emg8.addData(data);
                    break;
            }
        }

        public void packData()
        {
            if(listEMG.Count == 0)
            {
                listEMG.Add(emg1);
                listEMG.Add(emg2);
                listEMG.Add(emg3);
                listEMG.Add(emg4);
                listEMG.Add(emg5);
                listEMG.Add(emg6);
                listEMG.Add(emg7);
                listEMG.Add(emg8);
            }
        }


    }
}
