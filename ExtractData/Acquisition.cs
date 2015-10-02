using System;
using System.Threading;
using System.Windows.Forms;
using System.Xml;

namespace ExtractData
{
    public class Acquisition
    {

        private Main launchForm;
        public Emg emgs { get; set; }
        public Gyro gyro { get; set; }
        public Acce acce { get; set; }
        public Orientation orien { get; set; }
        public EulerOrientation eulorien { get; set; }
        public string[] filesData { get; set; }
        public string[] typeofdata { get; set; }
        public string[] subtypeDataEmg { get; set; }
        public string[] subtypeDataAcce { get; set; }
        public string[] subtypeDataGyro { get; set; }
        public string[] subtypeDataOrient { get; set; }
        public string[] subtypeDataEulerOrient { get; set; }

        public Acquisition( string[] files, Main form)
        {
            launchForm = form;
            emgs = new Emg();
            gyro = new Gyro();
            acce = new Acce();
            orien = new Orientation();
            eulorien = new EulerOrientation();
            filesData = files;
            typeofdata = new string[] { "Emg","Gyrometer","Accelerometer","Orientation","Euler's Orientation" };
            subtypeDataEmg = new string[] { "1", "2", "3", "4", "5", "6", "7", "8" };
            subtypeDataAcce = new string[] { "X", "Y", "Z"};
            subtypeDataGyro = new string[] { "X", "Y", "Z" };
            subtypeDataOrient = new string[] { "X", "Y", "Z", "W" };
            subtypeDataEulerOrient = new string[] { "roll", "pitch", "yaw"};
        }

        public void updateOutputLog(String text, int type)
        {
            this.launchForm.updateConsoleLog(text, type);
        }


        public void StartReadFile()
        {
            int nbData = 0;
            //int nbData = 0;
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
                else if (file.Contains("orientationEuler"))
                {
                    nbData = 3;
                }
                else if (file.Contains("orientation"))
                {
                    nbData = 4;
                }
                ReadFileNew(file, nbData);

            }

            //emgs.emg1.printData();

        }

        private void read(string file, int nbData)
        {
            XmlDocument xmlDoc = new XmlDocument();
            Console.WriteLine("#################====>>> " + file);
            this.updateOutputLog("Loading file : " + file, 0);
            xmlDoc.Load(file);
            try
            {
                
                foreach (XmlNode xmlNode in xmlDoc.DocumentElement)
                {
                    int compteur = 0;
                    foreach (XmlNode xmlChild in xmlNode)
                    {

                        if (file.Contains("emg"))
                        {
                            Console.WriteLine("xmlChild : " + xmlChild.InnerText);
                            this.updateOutputLog("Emg XML CHILD : " + xmlChild.InnerText, 0);
                            emgs.addData(compteur, double.Parse(xmlChild.InnerText.Replace(".", ",")));
                            compteur++;
                        }
                        else if (file.Contains("accelerometer"))
                        {
                            Console.WriteLine("xmlChild : " + xmlChild.InnerText);
                            this.updateOutputLog("accelerometer XML CHILD : " + xmlChild.InnerText, 0);
                            acce.addData(compteur, double.Parse(xmlChild.InnerText.Replace(".", ",")));
                            compteur++;
                        }
                        else if (file.Contains("gyro"))
                        {
                            Console.WriteLine("xmlChild : " + xmlChild.InnerText);
                            this.updateOutputLog("gyro XML CHILD : " + xmlChild.InnerText, 0);
                            gyro.addData(compteur, double.Parse(xmlChild.InnerText.Replace(".", ",")));
                            compteur++;
                        }
                        else if (file.Contains("orientationEuler"))
                        {
                            this.updateOutputLog("orientationEuler XML CHILD : " + xmlChild.InnerText, 0);
                            Console.WriteLine("xmlChild orientationEuler : " + xmlChild.InnerText);
                            eulorien.addData(compteur, double.Parse(xmlChild.InnerText.Replace(".", ",")));
                            compteur++;
                        }
                        else if (file.Contains("orientation"))
                        {

                            this.updateOutputLog("orientation XML CHILD : " + xmlChild.InnerText, 0);
                            Console.WriteLine("xmlChild : " + xmlChild.InnerText);
                            orien.addData(compteur, double.Parse(xmlChild.InnerText.Replace(".", ",")));
                            compteur++;
                        }
                    }
                    
                }
                xmlDoc = null;
                GC.Collect();
                GC.WaitForPendingFinalizers();
                
            }
            catch (FormatException format)
            {
                this.updateOutputLog("Erreur => Acquisition : format : " + format.Message, -1);
                Console.WriteLine("Acquisition : format : " + format.Message);
            }
            catch (Exception ex)
            {
                this.updateOutputLog("Erreur => Acquisition : general : " + ex.Message, -1);
                Console.WriteLine("Acquision : " + ex.Message);
            }
            this.launchForm.updateProgressBar();
        }

        private void readFile(string file, int nbData)
        {
            Thread readFile = new Thread(() => read(file, nbData));
            readFile.Start();

        }

        private void readNew(string file, int nbData, string textToEvaluate)
        {
            XmlDocument xmlDoc = new XmlDocument();
            Console.WriteLine("#################====>>> " + file);
            this.updateOutputLog("Loading file : " + file, 0);
            xmlDoc.Load(file);
            try
            {
                XmlNodeList xmlNodetest = xmlDoc.GetElementsByTagName(textToEvaluate);
                foreach (XmlNode xmlNode in xmlNodetest)
                {
                    if (textToEvaluate.Contains("emg"))
                    {
                        emgs.addDataByText(textToEvaluate, double.Parse(xmlNode.InnerXml.Replace(".", ",")));
                        this.updateOutputLog(textToEvaluate + " XML CHILD : " + xmlNode.InnerText, 0);
                    }
                    else if (file.Contains("accelerometer"))
                    {
                        acce.addDataByText(textToEvaluate, double.Parse(xmlNode.InnerXml.Replace(".", ",")));
                        this.updateOutputLog(textToEvaluate + " XML CHILD : " + xmlNode.InnerText, 0);
                    }
                    else if (file.Contains("gyrometer"))
                    {
                        gyro.addDataByText(textToEvaluate, double.Parse(xmlNode.InnerXml.Replace(".", ",")));
                        this.updateOutputLog(textToEvaluate + " XML CHILD : " + xmlNode.InnerText, 0);
                    }
                    else if (file.Contains("Euler"))
                    {
                        eulorien.addDataByText(textToEvaluate, double.Parse(xmlNode.InnerXml.Replace(".", ",")));
                        this.updateOutputLog(textToEvaluate + " XML CHILD : " + xmlNode.InnerText, 0);
                    }
                    else
                    {
                        orien.addDataByText(textToEvaluate, double.Parse(xmlNode.InnerXml.Replace(".", ",")));
                        this.updateOutputLog(textToEvaluate + " XML CHILD : " + xmlNode.InnerText, 0);
                    }
                }
            }
            catch (FormatException format)
            {
                this.updateOutputLog("Erreur => Acquisition : format : " + format.Message, -1);
                Console.WriteLine("Acquisition : format : " + format.Message);
            }
            catch (Exception ex)
            {
                this.updateOutputLog("Erreur => Acquisition : general : " + ex.Message, -1);
                Console.WriteLine("Acquision : " + ex.Message);
            }
            this.launchForm.updateProgressBar();
        }


        private void ReadFileNew(string file, int nbData)
        {
           
            if (file.Contains("emg"))
            {
                for(int i = 1; i<9; i++)
                {
                    String textToEvaluate = "emg" + i;
                    Thread readFile = new Thread(() => readNew(file, nbData,textToEvaluate));
                    readFile.Start();
                }
            }
            else if (file.Contains("accelerometer") || file.Contains("gyro"))
            {
                String[] listData = { "X", "Y", "Z" };
                foreach(String s in listData)
                {
                    Thread readFile = new Thread(() => readNew(file, nbData, s));
                    readFile.Start();
                }
            }
            else if (file.Contains("Euler"))
            {
                String[] listData = { "roll", "pitch", "yaw" };
                foreach (String s in listData)
                {
                    Thread readFile = new Thread(() => readNew(file, nbData, s));
                    readFile.Start();
                }
            }
            else
            {
                String[] listData = { "X", "Y", "Z","W"};
                foreach (String s in listData)
                {
                    Thread readFile = new Thread(() => readNew(file, nbData, s));
                    readFile.Start();
                }
            }
        }

    }
}
