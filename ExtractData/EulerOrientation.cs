using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractData
{
    public class EulerOrientation
    {
        public Data pitch { get; set; }
        public Data roll { get; set; }
        public Data yaw { get; set; }

        public EulerOrientation()
        {
            pitch = new Data("pitch");
            roll = new Data("roll");
            yaw = new Data("yaw");
        }

        public void addData(int pos, int data)
        {
            switch (pos)
            {
                case 0:
                    roll.addData(data);
                    break;
                case 1:
                    pitch.addData(data);
                    break;
                case 2:
                    yaw.addData(data);
                    break;
            }
        }

    }
}
