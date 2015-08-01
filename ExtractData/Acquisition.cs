using System;
using System.Xml;

namespace ExtractData
{
    public class Acquisition
    {
        public Emg emgs { get; set; }
        public Gyro gyro { get; set; }
        public Acce acce { get; set; }
        public Orientation orien { get; set; }
        public EulerOrientation eulorien { get; set; }
        public string[] filesData { get; set; }
        public Acquisition(string[] files)
        {
            emgs = new Emg();
            gyro = new Gyro();
            acce = new Acce();
            orien = new Orientation();
            eulorien = new EulerOrientation();
            filesData = files;
        }

        public void StartReadFile()
        {
            int nbData = 0;
            foreach (string file in filesData)
            {
                
                if (file.Contains("emg"))
                {
                    nbData = 8;
                }
                else if (file.Contains("accelerometer"))
                {
                    nbData = 3;
                }
                else if (file.Contains("gyro"))
                {
                    nbData = 3;
                }
                else if (file.Contains("orientation"))
                {
                    nbData = 4;
                }
                else if (file.Contains("orientationEuler"))
                {
                    nbData = 3;
                }

                readFile(file, nbData);
            }

            emgs.emg1.printData();

        }
        private void readFile(string file, int nbData)
        {
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(file);
            try
            {

                foreach (XmlNode xmlNode in xmlDoc.DocumentElement)
                {
                    foreach (XmlNode xmlChild in xmlNode)
                    {
                        int compteur = 0;
                        if (file.Contains("emg"))
                        {
                            emgs.addData(compteur, Convert.ToInt32(xmlChild.InnerText));
                            compteur++;
                            Console.WriteLine(xmlChild.Name);
                        }
                        else if (file.Contains("accelerometer"))
                        {
                            acce.addData(compteur, Convert.ToInt32(xmlChild.InnerText));
                            compteur++;
                        }
                        else if (file.Contains("gyro"))
                        {
                            gyro.addData(compteur, Convert.ToInt32(xmlChild.InnerText));
                            compteur++;
                        }
                        else if (file.Contains("orientation"))
                        {
                            orien.addData(compteur, Convert.ToInt32(xmlChild.InnerText));
                            compteur++;
                        }
                        else if (file.Contains("orientationEuler"))
                        {
                            eulorien.addData(compteur, Convert.ToInt32(xmlChild.InnerText));
                            compteur++; 
                        }
                        
                    }
                }
                Console.WriteLine(xmlDoc.ToString());
            }
            catch (Exception ex)
            {
                Console.WriteLine("MAIN : " + ex.Message);
            }
        }
    }
}
