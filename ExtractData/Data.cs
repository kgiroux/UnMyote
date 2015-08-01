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

        public List<int> dataList { get; set; }
        public string NameData { get; set; }

        public Data(string name)
        {
            dataList = new List<int>();
            NameData = name;
        }


        ~Data()
        {
            dataList = null;
        }
        public void addData(int data)
        {
            dataList.Add(data);
        }

        public void printData()
        {
            foreach (int data in dataList)
            {
                Console.WriteLine("Data : " + data);
            }
        }

    }

    
}
