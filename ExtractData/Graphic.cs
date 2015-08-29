using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;
using MathNet.Numerics.Transformations;

namespace ExtractData
{
    public partial class Graphic : Form
    {
        Acquisition acqData;
        private int heightInitPoint = 0;
        private int widthInitPoint = 0;
        private int heightZedGraph = 414;
        private ZedGraph.ZedGraphControl z1;
        private System.ComponentModel.Container components = null;
        private Panel pane;
        private Main formMain;
        public Graphic(Acquisition acq, Main form)
        {

            InitializeComponent();
            this.formMain = form;
            pane = new Panel();
            pane.Name = "Panel";
            pane.Height = this.ClientSize.Height;
            pane.Width = this.ClientSize.Width;
            pane.AutoScroll = true;
            acqData = acq;
            z1 = new ZedGraphControl();
            ToolStripMenuItem fileItem = new ToolStripMenuItem("Files");
            ToolStripMenuItem fourierItem = new ToolStripMenuItem("Fourier");
            ToolStripMenuItem OptionsItem = new ToolStripMenuItem("Settings");
            ToolStripMenuItem AboutItem = new ToolStripMenuItem("About");

            /* Menu */
            foreach (string type in acqData.typeofdata)
            {
                ToolStripMenuItem comp = new ToolStripMenuItem();
                ToolStripMenuItem fouriercomp = new ToolStripMenuItem();
                fouriercomp.Name = "dynamicItemFourier" + type;
                fouriercomp.Tag = "Fourier's " + type;
                fouriercomp.Text = "Fourier's " + type;
                comp.Name = "dynamicItem" + type;
                comp.Tag = type;
                comp.Text = type;
                string[] subtypelist = null;
                switch (type)
                {
                    case "Emg":
                        subtypelist = acqData.subtypeDataEmg;
                        break;
                    case "Gyrometer":
                        subtypelist = acqData.subtypeDataGyro;
                        break;
                    case "Accelerometer":
                        subtypelist = acqData.subtypeDataAcce;
                        break;
                    case "Orientation":
                        subtypelist = acqData.subtypeDataOrient;
                        break;
                    case "Euler's Orientation":
                        subtypelist = acqData.subtypeDataEulerOrient;
                        break;
                }
                if (subtypelist != null)
                {
                    foreach (string subtype in subtypelist)
                    {
                        ToolStripMenuItem sub_comp = new ToolStripMenuItem();
                        sub_comp.Name = "dynamicSubItem " + subtype;
                        sub_comp.Tag = type + " " + subtype;
                        sub_comp.Text = type + " " + subtype;
                        sub_comp.Click += new EventHandler(MenuItemClickHandler);
                        comp.DropDownItems.Add(sub_comp);
                    }

                    foreach (string subtype in subtypelist)
                    {
                        ToolStripMenuItem sub_comp_fourier = new ToolStripMenuItem();
                        sub_comp_fourier.Name = "dynamicSubItemFourier " + subtype;
                        sub_comp_fourier.Tag = "Fourier " + type + " " + subtype;
                        sub_comp_fourier.Text = "Fourier " + type + " " + subtype;
                        sub_comp_fourier.Click += new EventHandler(MenuItemClickHandlerFourier);
                        fouriercomp.DropDownItems.Add(sub_comp_fourier);
                    }

                }
                fileItem.DropDownItems.Add(comp);
                fourierItem.DropDownItems.Add(fouriercomp);
            }

            ToolStripMenuItem DisplayTrace = new ToolStripMenuItem("Display all Trace");

            foreach (string type in acqData.typeofdata)
            {
                ToolStripMenuItem subItemDisplay = new ToolStripMenuItem();
                subItemDisplay.Name = "DisplayALL" + type;
                subItemDisplay.Text = "Display all " + type;
                subItemDisplay.Tag = subItemDisplay.Text;
                subItemDisplay.Click += new EventHandler(MenuItemClickHandlerSettings);
                DisplayTrace.DropDownItems.Add(subItemDisplay);
            }

            ToolStripMenuItem DisplayTraceFourier = new ToolStripMenuItem("Display all Trace Fourier");
            foreach (string type in acqData.typeofdata)
            {
                ToolStripMenuItem subItemDisplay = new ToolStripMenuItem();
                subItemDisplay.Name = "DisplayALL" + type;
                subItemDisplay.Text = "Display all fourier " + type;
                subItemDisplay.Tag = subItemDisplay.Text;
                subItemDisplay.Click += new EventHandler(MenuItemClickHandlerSettings);
                DisplayTraceFourier.DropDownItems.Add(subItemDisplay);
            }

            ToolStripMenuItem CleanTrace = new ToolStripMenuItem("Clean all trace");
            CleanTrace.Name = "Clean Trace";
            CleanTrace.Text = "Clean Trace";
            CleanTrace.Tag = CleanTrace.Text;
            CleanTrace.Click += new EventHandler(MenuItemClickHandlerSettings);

            ToolStripMenuItem ResizeAxis = new ToolStripMenuItem("Resize Axis");
            ResizeAxis.Name = "Resize Axis";
            ResizeAxis.Text = "Resize Axis";
            ResizeAxis.Tag = ResizeAxis.Text;

            ToolStripMenuItem ResizeAxisY = new ToolStripMenuItem("Resize Axis Y ");
            ResizeAxisY.Name = "Resize Axis Y";
            ResizeAxisY.Text = "Resize Axis Y";
            ResizeAxisY.Tag = ResizeAxisY.Text;
            ResizeAxisY.Click += new EventHandler(MenuItemClickHandlerSettings);

            ToolStripMenuItem ResizeAxisX = new ToolStripMenuItem("Resize Axis X");
            ResizeAxisX.Name = "Resize Axis X";
            ResizeAxisX.Text = "Resize Axis X";
            ResizeAxisX.Tag = ResizeAxisX.Text;
            ResizeAxisX.Click += new EventHandler(MenuItemClickHandlerSettings);

            ResizeAxis.DropDownItems.Add(ResizeAxisX);
            ResizeAxis.DropDownItems.Add(ResizeAxisY);
            //OptionsItem.DropDownItems.Add(AddTrace);
            OptionsItem.DropDownItems.Add(DisplayTrace);
            OptionsItem.DropDownItems.Add(DisplayTraceFourier);
            OptionsItem.DropDownItems.Add(CleanTrace);
            OptionsItem.DropDownItems.Add(ResizeAxis);

            ToolStripMenuItem UnMyote = new ToolStripMenuItem("UnMyote");
            UnMyote.Name = "UnMyote";
            UnMyote.Text = "UnMyote";
            UnMyote.Tag = UnMyote.Text;
            UnMyote.Click += new EventHandler(MenuItemClickHandlerAbout);

            AboutItem.DropDownItems.Add(UnMyote);

            Menu.Items.Add(fileItem);
            Menu.Items.Add(fourierItem);
            Menu.Items.Add(OptionsItem);
            Menu.Items.Add(AboutItem);

            initZedGraph(z1, "z1");
        }

        public void initZedGraph(ZedGraphControl z1, string name)
        {

            
            // 
            // z1
            // 
            z1.IsShowPointValues = false;
            z1.Location = new System.Drawing.Point(widthInitPoint, heightInitPoint);
            z1.Name = "z1";
            z1.PointValueFormat = "G";
            z1.Size = new System.Drawing.Size(680, 414);
            z1.TabIndex = 0;
            // 
            // Form1
            // 
            AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            ClientSize = new System.Drawing.Size(680, 414);

            pane.Height = ClientSize.Height;
            pane.Width = ClientSize.Width;
            pane.Controls.Add(z1);
            Controls.Add(pane);
            Name = "Graph data";
            Text = "Graph Data";
            ResumeLayout(false);
        }

        /* Create Graph */
        private void CreateGraph(Data temp, string Title, Boolean fourier)
        {
            int compteur = 0;
            double[] x = null;
            double[] y = null;
            if (fourier)
            {
                x = new double[temp.dataList.Count / 2];
                y = new double[temp.dataList.Count / 2];
            }
            else
            {
                x = new double[temp.dataList.Count];
                y = new double[temp.dataList.Count];
            }


            z1.IsShowPointValues = true;
            z1.GraphPane.Title = Title;
            foreach (double data in temp.dataList)
            {
                if (x != null && y != null && fourier)
                {
                    if (compteur % 2 == 0)
                    {
                        y[compteur / 2] = data;
                    }
                    else
                    {
                        x[compteur / 2] = (compteur - 1) * 20;
                    }
                }
                else
                {
                    y[compteur] = data;
                    x[compteur] = compteur * 20;
                }
                compteur++;
            }
            Console.WriteLine("Count list : " + z1.GraphPane.CurveList.Count);
            if (z1.GraphPane.CurveList.Count > 0)
            {
                z1.GraphPane.CurveList.Clear();
            }

            z1.Refresh();
            z1.GraphPane.AddCurve("Signal", x, y, Color.Red, SymbolType.Circle);
            z1.GraphPane.XAxis.Max = x.Length * 20;
            z1.AxisChange();
            z1.Invalidate();
            System.IO.Directory.CreateDirectory("./images");
            z1.GraphPane.Image.Save("./images/" + Title + ".png");
        }
        private void CreateGraph(Data temp, string Title, ZedGraphControl z1, Boolean fourier)
        {
            int compteur = 0;
            double[] x = null;
            double[] y = null;
            if (fourier)
            {
                 x = new double[temp.dataList.Count/2];
                 y = new double[temp.dataList.Count/2];
            }
            else
            {
                x = new double[temp.dataList.Count];
                y = new double[temp.dataList.Count];
            }
             

            z1.IsShowPointValues = true;
            z1.GraphPane.Title = Title;
            foreach (double data in temp.dataList)
            {
                if(x != null && y != null && fourier)
                {
                    if (compteur % 2 == 0)
                    {
                        y[compteur/2] = data;
                    }
                    else
                    {
                        x[compteur/2] = (compteur -1)* 20;
                    }
                }
                else
                {
                    y[compteur] = data;
                    x[compteur] = compteur * 20;
                }
                compteur++;
            }
            Console.WriteLine("Count list : " + z1.GraphPane.CurveList.Count);
            if (z1.GraphPane.CurveList.Count > 0)
            {
                z1.GraphPane.CurveList.Clear();
            }

            z1.Refresh();
            z1.GraphPane.AddCurve("Signal", x, y, Color.Red, SymbolType.Circle);
            z1.GraphPane.XAxis.Max = x.Length * 20;
            z1.AxisChange();
            z1.Invalidate();
            System.IO.Directory.CreateDirectory("./images");
            z1.GraphPane.Image.Save("./images/"+Title+".png");
        }
        
       

        /* Add All Trace */
        private void AddAllMeasure(List<Data> temp)
        {
            int compteur = 0;
            foreach (Data data in temp)
            {
                ZedGraphControl z2 = new ZedGraphControl();
                heightInitPoint = heightZedGraph * compteur;
                compteur++;
                initZedGraph(z2,"z"+compteur);
                if(data != null)
                {
                    CreateGraph(data, data.NameData + "'s Data from Myo armhand ", z2, false);
                }
            }
        }
        private void AddAllFourier(List<Data> temp)
        {
            
            int compteur = 0;
            foreach (Data data in temp)
            {
                ZedGraphControl z2 = new ZedGraphControl();
                heightInitPoint = heightZedGraph * compteur;
                compteur++;
                initZedGraph(z2, "z" + compteur);
                if (data != null)
                {
                    TFFGRaphic(data, z2, false);
                }
            }
        }

        /* Menu Handler */
        private void MenuItemClickHandlerSettings(object sender, EventArgs e)
        {
            int newX;
            int newY;
            List<Data> temp;
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            Console.WriteLine(clickedItem.Tag);
            if(clickedItem.Tag.ToString() != "Resize Axis X" && clickedItem.Tag.ToString() != "Resize Axis Y")
                clearPane();
            switch (clickedItem.Tag.ToString())
            {
                case "Resize Axis Y":
                    Resize resizeY = new Resize("Y");
                    DialogResult resultY = resizeY.ShowDialog();
                    switch (resultY)
                    {
                        case DialogResult.OK:
                            newY = resizeY.SizeOfGraph;
                            this.updateOutputLog("New Y : " + newY, 1);
                            this.z1.GraphPane.YAxis.Max = newY;
                            this.z1.AxisChange();
                            this.z1.Invalidate();
                            break;
                        case DialogResult.Cancel:
                        default:
                            break;
                    }
                    break;
                case "Resize Axis X":
                    Resize resizeX = new Resize("X");
                    DialogResult resultX = resizeX.ShowDialog();
                    switch (resultX)
                    {
                        case DialogResult.OK:
                            newX = resizeX.SizeOfGraph;
                            this.updateOutputLog("New X : " + newX, 1);
                            this.z1.GraphPane.XAxis.Max = newX;
                            this.z1.AxisChange();
                            this.z1.Invalidate();
                            break;
                        case DialogResult.Cancel:
                        default:
                            break;
                    }
                    break;
                case "Display all Emg":
                    
                    acqData.emgs.packData();
                    temp = acqData.emgs.listEMG;
                    AddAllMeasure(temp);
                    break;
                case "Display all Gyrometer":
                    acqData.gyro.packData();
                    temp = acqData.gyro.listGyro;
                    AddAllMeasure(temp);
                    break;
                case "Display all Accelerometer":
                    acqData.acce.packData();
                    temp = acqData.acce.listAccero;
                    AddAllMeasure(temp);
                    break;
                case "Display all Orientation":
                    acqData.orien.packData();
                    temp = acqData.orien.listOrientation;
                    AddAllMeasure(temp);
                    break;
                case "Display all Euler's Orientation":
                    acqData.eulorien.packData();
                    temp = acqData.eulorien.listEulerOrientation;
                    AddAllMeasure(temp);
                    break;
                case "Display all fourier Emg":
                    acqData.emgs.packData();
                    temp = acqData.emgs.listEMG;
                    AddAllFourier(temp);
                    break;
                case "Display all fourier Gyrometer":
                    acqData.gyro.packData();
                    temp = acqData.gyro.listGyro;
                    AddAllFourier(temp);
                    break;
                case "Display all fourier Accelerometer":
                    acqData.acce.packData();
                    temp = acqData.acce.listAccero;
                    AddAllFourier(temp);
                    break;
                case "Display all fourier Orientation":
                    acqData.orien.packData();
                    temp = acqData.orien.listOrientation;
                    AddAllFourier(temp);
                    break;
                case "Display all fourier Euler's Orientation":
                    acqData.eulorien.packData();
                    temp = acqData.eulorien.listEulerOrientation;
                    AddAllFourier(temp);
                    break;
                case "Clean Trace":
                    clearPane();
                    break;
                default:
                    break;
            }
        }
        private void MenuItemClickHandlerAbout(object sender, EventArgs e)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            Console.WriteLine(clickedItem.Tag);
            switch (clickedItem.Tag.ToString())
            {
                case "UnMyote":
                    Unmyote un = new Unmyote();
                    un.ShowDialog();
                    break;
                default:
                    break;
            }
        }

        private void MenuItemClickHandlerFourier(object sender,EventArgs e)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            Console.WriteLine(clickedItem.Tag);
            Data temp = null;
            heightInitPoint = 0;
            switch (clickedItem.Tag.ToString())
            {
                case "Fourier Emg 1":
                    temp = acqData.emgs.emg1;
                    break;
                case "Fourier Emg 2":
                    temp = acqData.emgs.emg2;
                    break;
                case "Fourier Emg 3":
                    temp = acqData.emgs.emg3;
                    break;
                case "Fourier Emg 4":
                    temp = acqData.emgs.emg4;
                    break;
                case "Fourier Emg 5":
                    temp = acqData.emgs.emg5;
                    break;
                case "Fourier Emg 6":
                    temp = acqData.emgs.emg6;
                    break;
                case "Fourier Emg 7":
                    temp = acqData.emgs.emg7;
                    break;
                case "Fourier Emg 8":
                    temp = acqData.emgs.emg8;
                    break;
                case "Fourier Gyrometer X":
                    temp = acqData.gyro.X;
                    break;
                case "Fourier Gyrometer Y":
                    temp = acqData.gyro.Y;
                    break;
                case "Fourier Gyrometer Z":
                    temp = acqData.gyro.Z;
                    break;
                case "Fourier Accelerometer X":
                    temp = acqData.acce.X;
                    break;
                case "Fourier Accelerometer Y":
                    temp = acqData.acce.Y;
                    break;
                case "Fourier Accelerometer Z":
                    temp = acqData.acce.Z;
                    break;
                case "Fourier Orientation X":
                    temp = acqData.orien.X;
                    break;
                case "Fourier Orientation Y":
                    temp = acqData.orien.Y;
                    break;
                case "Fourier Orientation Z":
                    temp = acqData.orien.Z;
                    break;
                case "Fourier Orientation W":
                    temp = acqData.orien.W;
                    break;
                case "Fourier Euler's Orientation roll":
                    temp = acqData.eulorien.roll;
                    break;
                case "Fourier Euler's Orientation pitch":
                    temp = acqData.eulorien.pitch;
                    break;
                case "Fourier Euler's Orientation yaw":
                    temp = acqData.eulorien.yaw;
                    break;
                default:
                    temp = null;
                    break;
            }
            if(temp != null)
            {
                TFFGRaphic(temp,  true);
            }
            else
            {
                MessageBox.Show("No data found.Please check the xml file");
            }
        }
        private void MenuItemClickHandler(object sender, EventArgs e)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            Console.WriteLine(clickedItem.Tag);
            Data temp = null;
            heightInitPoint = 0;
            switch (clickedItem.Tag.ToString())
            {
                case "Emg 1":
                    temp = acqData.emgs.emg1;
                    break;
                case "Emg 2":
                    temp = acqData.emgs.emg2;
                    break;
                case "Emg 3":
                    temp = acqData.emgs.emg3;
                    break;
                case "Emg 4":
                    temp = acqData.emgs.emg4;
                    break;
                case "Emg 5":
                    temp = acqData.emgs.emg5;
                    break;
                case "Emg 6":
                    temp = acqData.emgs.emg6;
                    break;
                case "Emg 7":
                    temp = acqData.emgs.emg7;
                    break;
                case "Emg 8":
                    temp = acqData.emgs.emg8;
                    break;
                case "Gyrometer X":
                    temp = acqData.gyro.X;
                    break;
                case "Gyrometer Y":
                    temp = acqData.gyro.Y;
                    break;
                case "Gyrometer Z":
                    temp = acqData.gyro.Z;
                    break;
                case "Accelerometer X":
                    temp = acqData.acce.X;
                    break;
                case "Accelerometer Y":
                    temp = acqData.acce.Y;
                    break;
                case "Accelerometer Z":
                    temp = acqData.acce.Z;
                    break;
                case "Orientation X":
                    temp = acqData.orien.X;
                    break;
                case "Orientation Y":
                    temp = acqData.orien.Y;
                    break;
                case "Orientation Z":
                    temp = acqData.orien.Z;
                    break;
                case "Orientation W":
                    temp = acqData.orien.W;
                    break;
                case "Euler's Orientation roll":
                    temp = acqData.eulorien.roll;
                    break;
                case "Euler's Orientation pitch":
                    temp = acqData.eulorien.pitch;
                    break;
                case "Euler's Orientation yaw":
                    temp = acqData.eulorien.yaw;
                    break;
                default:
                    temp = null;
                    break;
            }
            if (temp != null)
            {
                clearPane();
                initZedGraph(z1, temp.NameData + "'s Data from Myo armhand ");
                CreateGraph(temp, temp.NameData + "'s Data from Myo armhand ", false);
            }
            else
            {
                MessageBox.Show("No data found.Please check the xml file");
            }
        }


        /* Transformer de fourrier */
        private void TFFGRaphic(Data temp, Boolean clear)
        {
            Console.WriteLine("ICI" + temp.NameData);
            int real = closest_pow(temp.dataList.Count);
            int size = (int)Math.Pow(2,real);
            size = size * 2;
            double[] listDouble = new double[size];
            int compteur = 0;
            foreach (double datatemp in temp.dataList)
            {
                if(compteur < listDouble.Length -1)
                {
                    listDouble[compteur] = datatemp;
                    compteur++;
                    listDouble[compteur] = 0.0;
                    compteur++;
                }
                
            }
            try
            {
                ComplexFourierTransformation cft = new ComplexFourierTransformation(TransformationConvention.Matlab);
                if ((size % 2 == 0) && listDouble.Length != 0)
                    cft.TransformForward(listDouble);
            }
            catch (System.ArgumentException ex)
            {
                Console.WriteLine("ICI erreur : " + ex.Message + "Size : " + size);
                this.updateOutputLog("Argument Exception Graphic.cs :" + ex.Message, -1);
            }

            //temp.dataList = listDouble.ToList<double>();
            Data tff = new Data(temp.NameData);
            tff.dataList = listDouble.ToList<double>();
            //TF TO BE DONE HERE ON TEMP VARIABLE
            if (clear)
                clearPane();
            initZedGraph(z1, temp.NameData + "'s Fourier Data from Myo armhand ");
            CreateGraph(tff, temp.NameData + "'s Fourier Data from Myo armhand ",  true);
        }
        private void TFFGRaphic(Data temp, ZedGraphControl z1,Boolean clear)
        {
            Console.WriteLine("ICI" + temp.NameData);
            int real = closest_pow(temp.dataList.Count);
            int size = (int)Math.Pow(2, real);
            size = size * 2;
            double[] listDouble = new double[size];
            int compteur = 0;
            foreach (double datatemp in temp.dataList)
            {
                listDouble[compteur] = datatemp;
                compteur++;
                listDouble[compteur] = 0.0;
                compteur++;
            }
            try
            {
                ComplexFourierTransformation cft = new ComplexFourierTransformation(TransformationConvention.Matlab);
                if ((size % 2 == 0) && listDouble.Length != 0)
                    cft.TransformForward(listDouble);
            }
            catch (System.ArgumentException ex)
            {
                Console.WriteLine("ICI erreur : " + ex.Message+ "Size : "+ size);
                this.updateOutputLog("Argument Exception Graphic.cs :" + ex.Message, -1);
            }

            //temp.dataList = listDouble.ToList<double>();
            Data tff = new Data(temp.NameData);
            tff.dataList = listDouble.ToList<double>();
            //TF TO BE DONE HERE ON TEMP VARIABLE
            if (clear)
                clearPane();
            CreateGraph(temp, temp.NameData + "'s Fourier Data from Myo armhand ", z1,true);
        }

        /* Utils */

        private void clearPane()
        {
            pane.Controls.Clear();
        }
        private int closest_pow(int x)
        {
            int i = 0;
            int p = 1;
            while (p < x)
            {
                p = p * 2;
                i++;
            }
            if ((p - x) < (x - p / 2))
            {
                return i;
            }
            else
            {
                return i - 1;
            }
        }

        public void updateOutputLog(String text, int type)
        {
            this.formMain.updateConsoleLog(text, type);
        }
    }
}
