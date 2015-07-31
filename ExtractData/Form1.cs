using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

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
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            // Set filter options and filter index.
            openFileDialog1.Filter = "XML Files (.xml)|*.xml|All Files (*.*)|*.*";
            openFileDialog1.FilterIndex = 1;

            openFileDialog1.Multiselect = true;
            XmlDocument xmlDoc = new XmlDocument();
            // Call the ShowDialog method to show the dialog box.
            DialogResult result = openFileDialog1.ShowDialog();

            // Process input if the user clicked OK.
            if (result == DialogResult.OK)
            {
                try
                {
                    xmlDoc.Load(openFileDialog1.FileName);
                    //reader = XmlReader.Create(openFileDialog1.FileName);
                    foreach(XmlNode xmlNode in xmlDoc.DocumentElement)
                    {
                        Console.WriteLine(xmlNode.Name);
                    }
                    Console.WriteLine(xmlDoc.ToString());
                    

                }
                catch(Exception ex)
                {
                    Console.WriteLine("MAIN : "  + ex.Message);
                }
            }
        }
    }
}
