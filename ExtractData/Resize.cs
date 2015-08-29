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

        public int SizeOfX { get; set; }
        public Resize()
        {
            InitializeComponent();
        }

        private void ResizeValue_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SizeOfX = Convert.ToInt32(ResizeValue.Text);
        }
    }
}
