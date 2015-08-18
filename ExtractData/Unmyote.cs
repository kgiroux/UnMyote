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
    public partial class Unmyote : Form
    {
        public Unmyote()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.unmyote.com");
        }

        private void facebookPict_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.facebook.com/pages/UnMyote/110064849324870");
        }

        private void TwitterPict_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://twitter.com/UnMyote");
        }

        private void GooglePict_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://plus.google.com/u/1/109924670256087185916/posts");
        }

        private void YoutubePict_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.youtube.com/channel/UCyoIXF4sV2KeNHZsbmU2fug");
        }

        private void label1_Click(object sender, EventArgs e)
        {
          
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.unmyote.com");
        }
    }
}
