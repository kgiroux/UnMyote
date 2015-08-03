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

namespace ExtractData
{
    public partial class Graphic : Form
    {
        Acquisition acqData;

        private ZedGraph.ZedGraphControl z1;
        private System.ComponentModel.Container components = null;

        public Graphic(Acquisition acq)
        {
            InitializeComponent();
            acqData = acq;
            z1 = new ZedGraphControl();
            ToolStripMenuItem fileItem = new ToolStripMenuItem("Files");
            ToolStripMenuItem fourierItem = new ToolStripMenuItem("Fourier");
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
               if(subtypelist != null)
                {
                    foreach (string subtype in subtypelist)
                    {
                        ToolStripMenuItem sub_comp = new ToolStripMenuItem();
                        sub_comp.Name = "dynamicSubItem " + subtype;
                        sub_comp.Tag = type + " " +subtype;
                        sub_comp.Text =  type + " " + subtype;
                        sub_comp.Click += new EventHandler(MenuItemClickHandler);
                        comp.DropDownItems.Add(sub_comp);
                    }

                    foreach (string subtype in subtypelist)
                    {
                        ToolStripMenuItem sub_comp_fourier = new ToolStripMenuItem();
                        sub_comp_fourier.Name = "dynamicSubItemFourier " + subtype;
                        sub_comp_fourier.Tag = "Fourier " + type + " " + subtype;
                        sub_comp_fourier.Text = "Fourier " + type + " " + subtype;
                        sub_comp_fourier.Click += new EventHandler(MenuItemClickHandler);
                        fouriercomp.DropDownItems.Add(sub_comp_fourier);
                    }

                }
                //comp.Click += new EventHandler(MenuItemClickHandler);
                fileItem.DropDownItems.Add(comp);
                fourierItem.DropDownItems.Add(fouriercomp);
            }
            Menu.Items.Add(fileItem);
            Menu.Items.Add(fourierItem);
            // 
            // z1
            // 
            this.z1.IsShowPointValues = false;
            this.z1.Location = new System.Drawing.Point(0, 0);
            this.z1.Name = "z1";
            this.z1.PointValueFormat = "G";
            this.z1.Size = new System.Drawing.Size(680, 414);
            this.z1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(680, 414);
            this.Controls.Add(this.z1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        private void CreateGraph(Data temp, string Title)
        {
            int compteur = 0;

            double[] x = new double[temp.dataList.Count];
            double[] y = new double[temp.dataList.Count];

            z1.IsShowPointValues = true;
            z1.GraphPane.Title = Title;
            foreach (double data in temp.dataList)
            {
                x[compteur] = compteur * 20;
                y[compteur] = data;
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
        }

        private void MenuItemClickHandler(object sender, EventArgs e)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            Console.WriteLine(clickedItem.Tag);
            Data temp = null;
            Boolean fourier = false;

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
                case "Fourier Emg 1":
                    fourier = true;
                    temp = acqData.emgs.emg1;
                    break;
                case "Fourier Emg 2":
                    fourier = true;
                    temp = acqData.emgs.emg2;
                    break;
                case "Fourier Emg 3":
                    fourier = true;
                    temp = acqData.emgs.emg3;
                    break;
                case "Fourier Emg 4":
                    fourier = true;
                    temp = acqData.emgs.emg4;
                    break;
                case "Fourier Emg 5":
                    fourier = true;
                    temp = acqData.emgs.emg5;
                    break;
                case "Fourier Emg 6":
                    fourier = true;
                    temp = acqData.emgs.emg6;
                    break;
                case "Fourier Emg 7":
                    fourier = true;
                    temp = acqData.emgs.emg7;
                    break;
                case "Fourier Emg 8":
                    fourier = true;
                    temp = acqData.emgs.emg8;
                    break;
                case "Fourier Gyrometer X":
                    fourier = true;
                    temp = acqData.gyro.X;
                    break;
                case "Fourier Gyrometer Y":
                    fourier = true;
                    temp = acqData.gyro.Y;
                    break;
                case "Fourier Gyrometer Z":
                    fourier = true;
                    temp = acqData.gyro.Z;
                    break;
                case "Fourier Accelerometer X":
                    fourier = true;
                    temp = acqData.acce.X;
                    break;
                case "Fourier Accelerometer Y":
                    fourier = true;
                    temp = acqData.acce.Y;
                    break;
                case "Fourier Accelerometer Z":
                    fourier = true;
                    temp = acqData.acce.Z;
                    break;
                case "Fourier Orientation X":
                    fourier = true;
                    temp = acqData.orien.X;
                    break;
                case "Fourier Orientation Y":
                    fourier = true;
                    temp = acqData.orien.Y;
                    break;
                case "Fourier Orientation Z":
                    fourier = true;
                    temp = acqData.orien.Z;
                    break;
                case "Fourier Orientation W":
                    fourier = true;
                    temp = acqData.orien.W;
                    break;
                case "Fourier Euler's Orientation roll":
                    fourier = true;
                    temp = acqData.eulorien.roll;
                    break;
                case "Fourier Euler's Orientation pitch":
                    fourier = true;
                    temp = acqData.eulorien.pitch;
                    break;
                case "Fourier Euler's Orientation yaw":
                    fourier = true;
                    temp = acqData.eulorien.yaw;
                    break;
            }
            if (temp != null)
            {
                if (!fourier)
                {
                
                    CreateGraph(temp, temp.NameData + "'s Data from Myo armhand ");
                }
                else // Calcul de la TF de 
                {
                    //TF TO BE DONE HERE ON TEMP VARIABLE
                    CreateGraph(temp, temp.NameData + "'s Fourier"   + " from Myo armhand's data");
                }
            }
            else
            {
                MessageBox.Show("No data found.Please check the xml file");
            }
        }
    }
}
