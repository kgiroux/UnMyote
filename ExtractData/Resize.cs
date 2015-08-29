using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExtractData
{
    public partial class Resize : Form
    {

        public int SizeOfGraph { get; set; }
        public Resize(string type)
        {
            InitializeComponent();
            label1.Text = type + "'s  new Size : ";
        }

        private void ResizeValue_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SizeOfGraph = Convert.ToInt32(ResizeValue.Text);
        }
    }
}
