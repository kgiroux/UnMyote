using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using ZedGraph;

namespace ExtractData
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Browse_Click(object sender, EventArgs e)
        {

            FolderBrowserDialog fbd = new FolderBrowserDialog();
            Console.WriteLine("PATH : " + Path.GetDirectoryName(Application.ExecutablePath));
            fbd.SelectedPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            DialogResult result = fbd.ShowDialog();
            string[] files = Directory.GetFiles(fbd.SelectedPath);

            Acquisition acq = new Acquisition(files);
            acq.StartReadFile();

            Graphic gph = new Graphic(acq);
            this.Hide();
            gph.ShowDialog();
            this.Close();

        }
    }
}
