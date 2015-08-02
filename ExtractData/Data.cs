using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{

   
    public class Data
    {
        //public List<int> dataList;

        public List<double> dataList { get; set; }
        public string NameData { get; set; }

        public Data(string name)
        {
            dataList = new List<double>();
            NameData = name;
        }


        ~Data()
        {
            dataList = null;
        }
        public void addData(double data)
        {
            dataList.Add(data);
        }

        public void printData()
        {
            foreach (double data in dataList)
            {
                Console.WriteLine("Data : " + data);
            }
        }

    }

    
}
